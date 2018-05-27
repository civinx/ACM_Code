//
//  main.cpp
//  2602 Bone Collector 01背包
//
//  Created by czf on 16/1/2.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
int c[maxn], w[maxn], res[maxn];
int main(){
    int t; scanf("%d",&t);
    while(t--){
        memset(res,0,sizeof(res));
        int n, V; scanf("%d%d",&n,&V);
        for(int i = 0; i < n; i ++) scanf("%d",&w[i]);
        for(int i = 0; i < n; i ++) scanf("%d",&c[i]);
        for(int i = 0; i < n; i ++){
            for(int v = V; v >= c[i]; v --){
                res[v] = max(res[v],res[v-c[i]]+w[i]);
            }
        }
        printf("%d\n",res[V]);
    }
    return 0;
}