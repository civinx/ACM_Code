//
//  main.cpp
//  5-1 最大子列和问题（分治法）
//
//  Created by czf on 15/12/6.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define maxn 100005
#define max(a,b) (a>b?a:b)
int a[maxn];
int solve(int *a, int x, int y){
    if (y-x == 1) return a[x];
    int m = x+(y-x)/2;
    int maxs = max(solve(a,m,y),solve(a,x,m));
    int v, r, l;
    l = a[m-1], v = 0;
    for(int i = m-1; i >= x; i --) {
        v += a[i];
        l = max(l,v);
    }
    r = a[m], v = 0;
    for(int i = m; i < y; i ++){
        v += a[i];
        r = max(r,v);
    }
    return max(maxs,l+r);
}
int main(){
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
    printf("%d\n",solve(a,0,n));
    return 0;
}