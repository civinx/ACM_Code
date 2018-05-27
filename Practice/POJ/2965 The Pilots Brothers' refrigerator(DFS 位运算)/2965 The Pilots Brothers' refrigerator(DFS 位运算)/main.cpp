//
//  main.cpp
//  2965 The Pilots Brothers' refrigerator(DFS 位运算)
//
//  Created by czf on 16/3/22.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int change[16] = {63624,62532,61986,61713,36744,20292,12066,7953,35064,17652,8946,4593,34959,17487,8751,4383};
bool flag = 0;

int r[16], c[16];
int myread(){
    string s;
    int ret = 0;
    for(int i = 0; i < 4; i ++){
        cin >> s;
        for(int j = 0; j < 4; j ++){
            ret = ret * 2 + (s[j] == '-' ? 1 : 0);
        }
    }
    return ret;
}

void dfs(int state, int pos, int cnt, int step){
    if (flag) return;
    if (cnt == step){
        if (state == 65535){
            flag = 1;
            printf("%d\n",cnt);
        }
        return;
    }
    if (pos > 15) return;
    int temp = state ^ change[pos];
    r[cnt] = pos / 4;
    c[cnt] = pos % 4;
    dfs(temp, pos+1, cnt+1, step);
    if (flag) return;
    dfs(state, pos+1, cnt, step);
    return;
}

int main(){
    int cur = myread();
    int i = 0;
    for(i = 0; i <= 16; i ++){
        dfs(cur, 0, 0, i);
        if (flag) break;
    }
    for(int j = 0; j < i; j ++)
        printf("%d %d\n",r[j]+1, c[j]+1);
    return 0;
}

//int main(){
//    for(int i = 0; i < 4; i ++){
//        for(int j = 0; j < 4; j ++){
//            int temp = 1;
//            temp = temp << ((3-i)*4 + (3-j));
//            for(int k = 0; k < 4; k ++){
//                if (k == j) continue;
//                temp ^= (1 << (3-i)*4 + (3-k));
//            }
//            for(int k = 0; k < 4; k ++){
//                if (k == i) continue;
//                temp ^= (1 << (3-k)*4 + (3-j));
//            }
//            printf("%d,",temp);
//        }
//    }
//}