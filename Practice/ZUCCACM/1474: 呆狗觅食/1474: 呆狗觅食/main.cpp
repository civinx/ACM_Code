//
//  main.cpp
//  1474: 呆狗觅食
//
//  Created by czf on 15/11/12.
//  Copyright © 2015年 czf. All rights reserved.
//


#include <cstdio>
#include <cstring>

const int maxn = 20;
int dp[maxn][maxn];
int n, m, a, b;

int solve(int x, int y){
    if (dp[x][y] >= 0) return dp[x][y];
    if (x == n && y == m) return 1;
    if ((x+1 <= n && (x+1 != a || y != b)) && (y+1 <= m && (y+1 != b || x != a)))
        return dp[x][y] = solve(x+1, y) + solve(x, y+1);
    else if (y+1 <= m && (y+1 != b || x != a))
        return dp[x][y] = solve(x, y+1);
    else if ((x+1 <= n && (x+1 != a || y != b)))
        return dp[x][y] = solve(x+1, y);
    else return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%d%d%d%d",&n,&m,&a,&b);
        if (n == a && m == b)
            printf("0\n");
        else
            printf("%d\n",solve(0, 0));
    }
}