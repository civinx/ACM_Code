//
//  main.cpp
//  Problem : xiaoxin juju needs help （杨辉三角+排列组合）
//
//  Created by czf on 16/4/3.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const int maxn = 500 + 10;
const int mod = 1e9 + 7;
int cnt[26];
ll c[maxn][maxn];

int main() {
    int t; scanf("%d",&t);
    memset(c, 0, sizeof(c));
    for(int i = 0; i < maxn; i ++) c[i][0] = 1;
    for(int i = 1; i < maxn; i ++) {
        for(int j = 1; j <= i; j ++){
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
        }
    }
//    for (int i = 0; i < 20; i ++) {
//        for (int j = 0; j < 20; j ++) {
//            printf("%lld ",c[i][j]);
//        }
//        printf("\n");
//    }
    while(t--) {
        memset(cnt, 0, sizeof(cnt));
        string s; cin >> s;
        int len = s.size();
        int flag = 0;
        for(auto ci : s) cnt[ci-'a'] ++;
        for(int i = 0; i < 26; i ++) {
            if (flag && cnt[i] % 2) { flag = 2; break; }
            if (!flag && cnt[i] % 2) flag = 1;
        }
        if (flag == 2) { printf("0\n"); continue; }
        for (int i = 0; i < 26; i ++) cnt[i] /= 2;
        len /= 2;
        ll res = 1;
        for(int i = 0; i < 26; i ++) {
            res = ((res % mod) * (c[len][cnt[i]] % mod)) % mod;
            len -= cnt[i];
        }
        printf("%lld\n",res);
    }
    return 0;
}