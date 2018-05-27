//
//  main.cpp
//  Problem : 金子大爷
//
//  Created by czf on 16/4/15.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int maxn = 100000 + 100;
const int mod = 790660457;
typedef long long ll;
ll f[100+10][maxn];
int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n, m; scanf("%d%d",&n,&m);
        memset(f, 0, sizeof(f));
        for (int i = 0; i <= m; i ++) f[1][i] = 1;
        for (int i = 2; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (n-i+1 >= j) {
                    f[i][j] = (f[i][j] + f[i-1][j]) % mod;
                    continue;
                }
                f[i][j] = (f[i-1][j] + f[i-1][j-(n-i+1)]) % mod;
            }
        }
        printf("%lld\n",f[n][m]);
    }
    return 0;
}