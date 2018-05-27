//
//  main.cpp
//  5937 Equation（搜索 剪枝）
//
//  Created by czf on 2016/11/18.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100;

int dp[maxn][3]; //存等式，第一维表示第几个等式，第二维表示等式中的三个数字
int a[10]; //每个数字目前还可以用几次
int cnt = 0, res = 0;
map<int, int> mp; //映射每个数字在所有可能的等式中出现的次数

void init() { //预处理出所有可能的等式
    for (int i = 1; i < 9; i ++) {
        for (int j = 1; j+i <= 9; j ++) {
            dp[cnt][0] = i;
            dp[cnt][1] = j;
            dp[cnt][2] = i+j;
            mp[i] ++;
            mp[j] ++;
            mp[i+j] ++;
            cnt ++;
        }
    }
//    cout << cnt << endl; //等式共有36个
}

bool check(int pos) { //检查可不可以满足第pos个等式
    for (int i = 0; i < 3; i ++) {
        if (a[dp[pos][i]] <= 0) return false;
    }
    if (dp[pos][0] == dp[pos][1]) { //如果是等式前两个数字一样，那么它们至少要两个
        return a[dp[pos][0]] >= 2;
    }
    return true;
}

void update(int pos, int val) {
    for (int i = 0; i < 3; i ++) {
        a[dp[pos][i]] += val;
    }
}

void dfs(int pos, int sum) {
    if (pos >= cnt) return; //搜完最后一个等式了
    if (cnt - pos + sum <= res) return; //就算后面所有的等式都成立，再加上之前的累积，也没有目前答案大，剪枝
    if (check(pos)) {
        update(pos, -1); //把数字用掉
//        printf("%d+%d=%d\n",dp[pos][0],dp[pos][1],dp[pos][2]);
        res = max(res, sum+1); //更新答案
        dfs(pos+1, sum+1); //搜下一个等式，答案累加1
        update(pos, 1); //回溯
    }
    dfs(pos+1, sum); //搜下一个等式，答案不加
}

int main() {
    init();
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        bool flag = 1;
        res = 0;
        for (int i = 1; i <= 9; i ++) {
            scanf("%d",&a[i]);
            a[i] = min(a[i], mp[i]); //如果多于最多需要的数量，就鸽掉
            if (a[i] < mp[i]) flag = 0;
        }
        if (flag) res = cnt; //每个数字都有最多需要的数量，直接输出所有等式的数量
        else dfs(0, 0);
        printf("Case #%d: %d\n",++kase, res);
    }
    return 0;
}
