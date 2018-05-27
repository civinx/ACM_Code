//
//  main.c
//  Problem : Frog
//
//  Created by czf on 15/10/23.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define max(x,y) x>y ? x:y;
#define maxn 105
int main() {
    int sum[maxn*10][maxn];
    int insects[maxn];
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(sum, 0, sizeof(sum));
        int res = 0;
        int n, a, b, k;
        scanf("%d%d%d%d",&n,&a,&b,&k);
        for (int i = 1; i <= n; i ++) scanf("%d",&insects[i]);
        for (int i = 1; i <= k; i ++) { //跳K次
            for (int j = 1; j <= i*b-b+1; j ++) { 
                for (int x = j+a; x <= j+b && x<=n; x ++) {
                    sum[i][x] = max(sum[i][x], sum[i-1][j] + insects[x]);
                    res = max(res, sum[i][x]);
                }
            }
        }
        printf("%d\n",res+insects[1]);
    }
    return 0;
}
