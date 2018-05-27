//
//  main.cpp
//  1068 Parencodings（模拟）
//
//  Created by czf on 16/4/13.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

bool vis[10000];
int main () {
    int t; scanf("%d",&t);
    while (t--) {
        memset(vis, 0, sizeof(vis));
        int n; scanf("%d",&n);
        string s;
        int cnt = 0, ans;
        for (int i = 0; i < n; i ++) {
            int x; scanf("%d",&x);
            ans = x - cnt;
            cnt += ans;
            for (int j = 0; j < ans; j ++) s += '(';
            s += ')';
        }
        int len = (int)s.size(); bool flag = 1;
        for (int i = 0; i < len; i ++) {
            if (s[i] == ')') {
                cnt = 0;
                for (int j = i-1; j >= 0; j --) {
                    if (s[j] == '(' && !vis[j]) { cnt ++; vis[j] = 1; break; }
                    if (s[j] == ')' && vis[j]) cnt ++;
                }
                vis[i] = 1;
                if (flag) { printf ("%d",cnt); flag = 0;}
                else printf(" %d",cnt);
            }
        }
        printf("\n");
    }
    return 0;
}
