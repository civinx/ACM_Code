//
//  main.cpp
//  2087 剪花布条
//
//  Created by czf on 16/1/30.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 1000 + 10;
char T[maxn], P[maxn];
int f[maxn];

int getFail(){
    int n = strlen(P);
    f[0] = f[1] = 0;
    for(int i = 1; i < n; i ++){
        int j = f[i];
        while(j && P[i]!=P[j]) j = f[j];
        f[i+1] = P[i]==P[j] ? j+1 : 0;
    }
    return n;
}

int find(){
    int m = getFail();
    int n = strlen(T);
    int j = 0, ret = 0;
    for(int i = 0; i < n; i ++){
        while(j && T[i] != P[j]) j = f[j];
        if (T[i] == P[j]) j ++;
        if (j == m) {j = 0; ret ++;}
    }
    return ret;
}

int main(){
    while(scanf("%s",T) && T[0]!='#'){
        scanf("%s",P);
        printf("%d\n",find());
    }
    return 0;
}
