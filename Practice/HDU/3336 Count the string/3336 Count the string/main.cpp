//
//  main.cpp
//  3336 Count the string
//
//  Created by czf on 16/1/29.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
typedef long long ll;
const int maxn = 200000 + 100;
char s[maxn]; int f[maxn], dp[maxn], n;

void getFail(int n, int* f){
    f[0] = f[1] = 0;
    for(int i = 1; i < n; i ++){
        int j = f[i];
        while(j && s[i]!=s[j]) j = f[j];
        f[i+1] = s[j]==s[i] ? j+1 : 0;
    }
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,s);
        ll res = 0;
        dp[0] = 0;
        getFail(n, f);
        for(int i = 1; i <= n; i++){
            dp[i] = 1 + dp[f[i]];
            res = (res+dp[i])%10007;
        }
        printf("%lld\n",res);
    }
    return 0;`
}