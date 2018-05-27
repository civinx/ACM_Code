//
//  main.cpp
//  3746 Cyclic Nacklace
//
//  Created by czf on 16/1/30.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 100000 + 100;
char s[maxn]; int f[maxn];

void getFail(int n){
    f[0] = f[1] = 0;
    for(int i = 1; i <= n; i ++){
        int j = f[i];
        while(j && s[i]!=s[j]) j = f[j];
        f[i+1] = s[i]==s[j] ? j+1 : 0;
    }
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n;
        scanf("%s",s);
        n = strlen(s);
        getFail(n);
        int ans = n-f[n], res = 0;
        if (n == ans) res = n;
        else if (n % ans) res = ans - (n-ans*(n/ans));
        printf("%d\n",res);
    }
    return 0;
}