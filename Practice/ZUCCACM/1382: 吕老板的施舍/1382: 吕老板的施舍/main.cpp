//
//  main.cpp
//  1382: 吕老板的施舍
//
//  Created by czf on 15/12/4.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 50000;
int a[35],left[maxn], right[maxn], mid;
int m, n, cnt_l,cnt_r;

void dfs_l(int x, int sum){
    if (x >= mid){
        left[cnt_l++] = sum;
        return;
    }
    dfs_l(x+1,sum);
    dfs_l(x+1,sum+a[x]);
}

void dfs_r(int x, int sum){
    if (x >= n){
        right[cnt_r++] = sum;
        return;
    }
    dfs_r(x+1,sum);
    dfs_r(x+1,sum+a[x]);
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        std::sort(a,a+n);
        mid = n/2; cnt_l =0;
        dfs_l(0,0);
        cnt_r = 0;
        dfs_r(mid,0);
        std::sort(left,left+cnt_l); std::sort(right,right+cnt_r);
        int res = 0, ans = cnt_r-1;
        for(int i = 0; i < cnt_l; i ++){
            for(int j = ans; j >= 0; j--){
                if (left[i] + right[j] <= m){
                    if (left[i] + right[j] > res)
                        res = left[i] + right[j];
                    break;
                }
                else{
                    ans = j-1;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}