//
//  main.cpp
//  D. The Union of k-Segments
//
//  Created by czf on 15/12/26.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000000 + 50;
int l[maxn], r[maxn];
int rl[maxn], rr[maxn];
int main(){
    int n, k; scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i ++)
        scanf("%d%d",&l[i],&r[i]);
    sort(l,l+n); sort(r,r+n);
    int i = 0, j = 0, cnt = 0, kase = 0;
    bool flag = 0;
    while(i<n || j<n){
        if(l[i] <= r[j] && i < n){
            cnt ++; i ++;
        }
        else{
            cnt --; j ++;
        }
        if (cnt == k && !flag){
            flag = 1; rl[kase++] = l[i-1];
        }
        if (cnt == k-1 && flag){
            flag = 0; rr[kase-1] = r[j-1];
        }
    }
    printf("%d\n",kase);
    for(int i = 0; i < kase; i++){
        printf("%d %d\n",rl[i],rr[i]);
    }
    return 0;
}