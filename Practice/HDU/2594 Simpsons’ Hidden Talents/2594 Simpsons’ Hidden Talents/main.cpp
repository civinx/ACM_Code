//
//  main.cpp
//  2594 Simpsons’ Hidden Talents
//
//  Created by czf on 16/1/30.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 50000 + 100;
char s1[maxn*2], s2[maxn];
int f[maxn*2];

int getFail(){
    int k = strlen(s1);
    f[0] = f[1] = 0;
    for(int i = 1; i < k; i ++){
        int j = f[i];
        while(j && s1[i]!=s1[j]) j = f[j];
        f[i+1] = s1[i]==s1[j] ? j+1 : 0;
    }
    return k;
}

int main(){
    while(scanf("%s%s",s1,s2) != EOF){
        int n = strlen(s1);
        int m = strlen(s2);
        strcat(s1,s2);
        int k = getFail();
        while (f[k] > n || f[k] > m) k = f[k];
        if (f[k] > 0){
            for (int i = 0; i < f[k]; i ++) putchar(s1[i]);
            putchar(' ');
        }
        printf("%d\n",f[k]);
    }
    return 0;
}