//
//  main.cpp
//  1087 Super Jumping! Jumping! Jumping!(DP)
//
//  Created by czf on 15/12/9.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 1000 + 5;
int a[maxn], dp[maxn];
int main(){
    int n;
    while(scanf("%d",&n) && n){
        for(int i = 1; i <= n; i ++) scanf("%d",&a[i]);
        dp[1] = a[1]; int ans = 0;
        for(int i = 2; i <= n; i ++){
            ans = 0;
            for(int j = 1; j < i; j ++){
                if(a[j] < a[i] && dp[j] > ans) ans = dp[j];
            }
            dp[i] = ans+a[i];
        }
        ans = dp[1];
        for(int i = 1; i <= n; i ++){
            if (dp[i] > ans) ans = dp[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}