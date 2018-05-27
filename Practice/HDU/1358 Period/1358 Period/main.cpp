//
//  main.cpp
//  1358 Period
//
//  Created by czf on 16/1/30.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 1000000 + 100;
char s[maxn];
int f[maxn];

void getFail(int n){
    f[0] = f[1] = 0;
    for(int i = 1; i < n; i ++){
        int j = f[i];
        while(j && s[i]!=s[j]) j = f[j];
        f[i+1] = s[i]==s[j] ? j+1 : 0;
    }
}

int main(){
    int n, kase = 0;
    while(scanf("%d",&n) && n){
        scanf("%s",s);
        getFail(n);
        printf("Test case #%d\n",++kase);
        for(int i = 2; i <= n; i ++){
            if (i%(i-f[i]) == 0 && f[i])
                printf("%d %d\n",i,i/(i-f[i]));
        }
        putchar('\n');
    }
    return 0;
}