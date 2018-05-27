//
//  main.cpp
//  2084 数塔
//
//  Created by czf on 15/11/15.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
int a[maxn][maxn];
int dp[maxn][maxn];
int n;

int solve(int i, int j){
    if (dp[i][j] >= 0) return dp[i][j];
    return dp[i][j] = a[i][j] + (i == n ? 0 : max(solve(i+1,j),solve(i+1,j+1)));
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= i; j ++)
                scanf("%d",&a[i][j]);
        }
        printf("%d\n",solve(1,1));
    }
    return 0;
}