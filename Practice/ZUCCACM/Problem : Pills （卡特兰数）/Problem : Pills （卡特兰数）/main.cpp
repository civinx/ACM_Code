//
//  main.cpp
//  Problem : Pills （卡特兰数）
//
//  Created by czf on 16/4/2.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
typedef long long ll;
const int maxn = 100;
ll f[maxn][maxn];

int main() {
    for(int i = 0; i < maxn; i ++) f[0][i] = 1;
    for(int i = 1; i <= 30; i ++) {
        for(int j = 0; j <= 30; j ++) {
            f[i][j] = f[i-1][j+1] + (j == 0 ? 0 : f[i][j-1]);
        }
    }
    int n;
    while(scanf("%d",&n) && n) {
        printf("%lld\n",f[n][0]);
    }
    return 0;
}