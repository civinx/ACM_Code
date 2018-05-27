//
//  main.cpp
//  1530: 伦狗的矩阵
//
//  Created by czf on 15/11/20.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 20 + 5;
int a[maxn][maxn], n;

void solve(int x, int y, int ans){
    if(y == n + 1) return;
    a[x][y] = ans;
    if(y == 1) solve(1,x+1,++ans);
        else solve(x+1,y-1,++ans);
}

int main(){
    while(scanf("%d",&n) == 1){
        memset(a,0,sizeof(a));
        int ans = 1;
        solve(1,1,ans);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n-i+1; j ++){
                printf("%d",a[i][j]);
                if (j != n-i+1) printf(" ");
            }
            printf("\n");
        }
    }
}