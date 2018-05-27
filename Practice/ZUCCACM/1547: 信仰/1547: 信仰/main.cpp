//
//  main.cpp
//  1547: 信仰
//
//  Created by czf on 15/11/19.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 50000 + 5;
int father[maxn];

int root(int x){
    return x == father[x] ? x : father[x] = root(father[x]);
}

int main(){
    int n, m, kase = 0;
    while(scanf("%d%d",&n,&m)==2 && (n || m)){
        for(int i = 1; i <= n; i ++) father[i] = i;
        while(m--){
            int a, b;
            scanf("%d%d",&a,&b);
            a = root(a); b = root(b);
            if (a == b) continue;
            father[b] = a;
            n --;
        }
        printf("Case %d: %d\n",++kase,n);
    }
}