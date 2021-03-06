//
//  main.cpp
//  Problem : Frosh Week
//
//  Created by czf on 15/12/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 1000000 + 1000;
int a[maxn], temp[maxn];
long long cnt = 0;
void solve(int *a, int x, int y, int *t){
    if (y-x > 1){
        int m = x+(y-x)/2;
        int p = x, q = m, i = x;
        solve(a,x,m,t);
        solve(a,m,y,t);
        while(p < m || q < y){
            if (q >= y || (p < m && a[p] < a[q]))
                t[i++] = a[p++];
            else {
                t[i++] = a[q++];
                cnt += m-p;
            }
        }
        for(int i = x; i < y; i ++) a[i] = t[i];
    }
}
int main(){
    int n;
    while(scanf("%d",&n) == 1){
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        cnt = 0;
        solve(a,0,n,temp);
        printf("%lld\n",cnt);
    }
    return 0;
}
