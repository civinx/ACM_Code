//
//  main.cpp
//  2182 Frog
//
//  Created by czf on 15/12/9.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#define max(a,b) a>b?a:b
const int maxn = 100 + 5;
int main(){
    int t, ins[maxn], dp[maxn][maxn]; scanf("%d",&t);
    while(t--){
        int n, a, b, k; scanf("%d%d%d%d",&n,&a,&b,&k);
        for(int i = 0; i < n; i ++) scanf("%d",&ins[i]);
        memset(dp,0,sizeof(dp));
        int res;
        res = dp[0][0] = ins[0];
        for(int i = 1; i <= k; i ++){
            for(int j = (i-1)*a; j <= (i-1)*b; j ++){
                for(int x = j+a; x <= j+b && x<=n; x ++){
                    dp[i][x] = max(dp[i-1][j]+ins[x],dp[i][x]);//决定是否更新
                    res = max(res,dp[i][x]);
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}



