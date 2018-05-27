//
//  main.cpp
//  靶形数独
//
//  Created by czf on 2017/2/9.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10;
const int MASK = (1 << 10) - 2; //1111111110 (2)

//方格盘上的数字, 下标从1开始计数, res: 答案
int a[MAXN][MAXN], res = -1;


//row: 每行的使用过的数字的情况, 若数字i被用过, 则二进制从低位开始数第i位为1
//col: 每列的使用过的数字的情况
//cell: 每一个小九宫格的使用过的数字的情况, 下标从0开始计数
int row[MAXN], col[MAXN], cell[MAXN/3][MAXN/3];

//ncnt: 每行格子目前有数字的个数
//empty: 每行的格子空余情况, 二进制0代表空着, 1代表有数字, 被用来优化搜索顺序
//seq: 搜索行的顺序
int empty[MAXN], ncnt[MAXN], seq[MAXN];

//输入数据
void Read() {
    for (int i = 1; i <= 9; i ++) {
        for (int j = 1; j <= 9; j ++) {
            cin >> a[i][j];
        }
    }
}

//检查一个数字是否可以放到a[i][j]中
bool Check(int number, int i, int j) {
    if (row[i] & (1 << number)) return false;
    if (col[j] & (1 << number)) return false;
    if (cell[(i-1)/3][(j-1)/3] & (1 << number)) return false;
    return true;
}

//添加一个数字到a[i][j]中, 并更改状态
void AddNumber(int number, int i, int j) {
    int state = 1 << number;
    row[i] |= state;
    col[j] |= state;
    cell[(i-1)/3][(j-1)/3] |= state;
    
    int state_empty = 1 << j;
    empty[i] |= state_empty;
    ncnt[i] ++;
}

//把数字a[i][j]拿掉, 并更改状态
void DeleteNumber(int number, int i, int j) {
    int state = 1 << number;
    row[i] ^= state;
    col[j] ^= state;
    cell[(i-1)/3][(j-1)/3] ^= state;
    
    int state_empty = 1 << j;
    empty[i] ^= state_empty;
    ncnt[i] --;
}

bool cmp(int i, int j) {
    return ncnt[i] > ncnt[j];
}

bool Init() {
    for (int i = 1; i <= 9; i ++) {
        seq[i] = i;
    }
    for (int i = 1; i <= 9; i ++) {
        for (int j = 1; j <= 9; j ++) {
            if (a[i][j]) {
                if (!Check(a[i][j], i, j)) return false;
                
                AddNumber(a[i][j], i, j);
            }
        }
    }
    sort(seq+1, seq+10, cmp);
    return true;
}

void Count() {
    int sum = 0;
    for (int k = 1; k < 5; k ++) {
        int score = 10 - k;
        for (int j = 5-k; j <= 5+k; j ++) sum += score * (a[5+k][j] + a[5-k][j]);
        for (int j = 5-k+1; j < 5+k; j ++) sum += score * (a[j][5+k] + a[j][5-k]);
    }
    sum += a[5][5] * 10;
    res = max(res, sum);
}

//返回从二进制低位数第一个1对应的十进制, 如x是14(10),1110(2), 那么返回2, 10(2)
inline int lowbit(int x) {
    return x & -x;
}

void dfs(int dep) {
    if (dep == 10) {
        Count();
        return;
    }
    int x = seq[dep];
    int y = (int)log2(lowbit(MASK ^ empty[x])); //从低位数第一个空的位置
    
    int numberSet = row[x] | col[y] | cell[(x-1)/3][(y-1)/3];
    while (numberSet != MASK) {
        int num = (int)log2(lowbit(MASK ^ numberSet));
        numberSet |= 1 << num;
        if (Check(num, x, y)) {
            AddNumber(num, x, y);
            a[x][y] = num;
            if (ncnt[x] == 9) dfs(dep+1);
            else dfs(dep);
            DeleteNumber(num, x, y);
            a[x][y] = 0;
        }
    }
}

int main() {
    Read();
    if (!Init()) {
        cout << -1 << '\n';
    } else {
        int i = 1;
        while (seq[i] != 9) i ++;
        dfs(1);
        cout << res << '\n';
    }
    return 0;
}
