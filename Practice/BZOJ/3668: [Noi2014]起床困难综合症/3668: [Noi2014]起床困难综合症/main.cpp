//
//  main.cpp
//  3668: [Noi2014]起床困难综合症
//
//  Created by czf on 2017/3/7.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int maxn = 1e5 + 100;

vector<bool> door[maxn], res, st; //0放最低位

short op[maxn]; //1AND, 2OR, 3XOR

void init(vector<bool> &v, int x) {
    while (x) {
        v.push_back(x % 2);
        x /= 2;
    }
}

bool solve(bool x, int n, int pos) {
    for (int i = 0; i < n; i ++) {
        if (op[i] == 1) {
            x &= door[i][pos];
        } else if (op[i] == 2) {
            x |= door[i][pos];
        } else {
            x ^= door[i][pos];
        }
    }
    return x;
}

int main() {
    int n, m; scanf("%d%d",&n,&m);
    init(st, m);
    for (int i = 0; i < n; i ++) {
        char temp[10]; int x; scanf("%s%d",temp,&x);
        if (temp[0] == 'A') op[i] = 1;
        else if (temp[0] == 'O') op[i] = 2;
        else op[i] = 3;
        init(door[i], x);
        while (door[i].size() < st.size()) door[i].push_back(0);
    }
    
    bool limit = 1;
    for (int i = (int)st.size()-1; i >= 0; i --) {
        int end = limit ? st[i] : 1;
        int ret = -1;
        for (int j = end; j >= 0; j --) {
            if (solve(j, n, i)) {
                ret = j;
            }
        }
        if (ret == -1) {
            limit = (limit && !st[i]);
            res.push_back(0);
        } else {
            limit = (limit && (ret == end));
            res.push_back(1);
        }
//        printf("ret = %d, i = %d\n",ret, i);
    }
    int ans = 0;
    for (int i = 0; i < res.size() ; i ++) ans = ans * 2 + res[i];
    printf("%d\n",ans);
    return 0;
}



