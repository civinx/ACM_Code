//
//  main.cpp
//  2191 悼念512汶川大地震遇难同胞――珍惜现在，感恩生活
//
//  Created by czf on 16/2/22.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int c[maxn], w[maxn], m[maxn], f[maxn];
int v, n;
void ZeroOnePack(int c, int w);
void CompletePack(int c, int w);
void MultiplePack(int c, int w, int m);

int main(){
    int t; scanf("%d",&t);
    while(t--){
        memset(f, 0, sizeof(f));
        scanf("%d%d",&v,&n);
        for(int i = 1; i <= n; i ++)
            scanf("%d%d%d",&c[i],&w[i],&m[i]);
        for(int i = 1; i <= n; i ++)
            MultiplePack(c[i], w[i], m[i]);
        int res = 0;
        for(int i = 0; i <= v; i ++)
            res = max(res, f[i]);
        printf("%d\n",res);
    }
    return 0;
}

void ZeroOnePack(int c, int w){
    for(int i = v; i >= c; i --)
        f[i] = max(f[i], f[i-c]+w);
}

void CompletePack(int c, int w){
    int m = v/c, k = 1;
    while(m > k){
        ZeroOnePack(c*k, w*k);
        m -= k;
        k = k << 1;
    }
    ZeroOnePack(c*m, w*m);
}

void MultiplePack(int c, int w, int m){
    if (c * m >= v)
        CompletePack(c, w);
    else{
        int k = 1;
        while(m > k){ //13 1  12 2  10 4  6 8
            ZeroOnePack(c*k, w*k);
            m -= k;
            k = k << 1;
        }
        ZeroOnePack(c*m, w*m);
    }
}