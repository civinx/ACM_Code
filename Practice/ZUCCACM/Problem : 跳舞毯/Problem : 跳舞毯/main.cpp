//
//  main.cpp
//  Problem : 跳舞毯
//
//  Created by czf on 15/11/13.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int mod = 10000;
const int maxn = 1000 + 5;
int main() {
    int n, a[maxn] = {1}, b[maxn] = {0}, c[maxn] = {0};
    for (int i = 1; i <= maxn; i ++) {
        a[i] = (b[i-1] + c[i-1])%mod;
        b[i] = (a[i-1] + c[i-1])%mod;
        c[i] = (a[i-1] + b[i-1])%mod;
    }
    while (scanf("%d",&n) == 1 && n) {
        printf("%d\n",a[n]);
    }
    return 0;
}
