//
//  main.cpp
//  2553 N皇后问题
//
//  Created by czf on 15/11/24.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
int n, cnt, a[3][20];
int res[15];
void solve(int x){
    if(x == n) cnt ++;
    else for(int i = 0; i < n; i ++){
        if(!a[0][i] && !a[1][x+i] && !a[2][x-i+n]){
            a[0][i] = a[1][x+i] = a[2][x-i+n] = 1;
            solve(x+1);
            a[0][i] = a[1][x+i] = a[2][x-i+n] = 0;
        }
    }
}
int main(){
    memset(res, -1, sizeof(res));
    while(scanf("%d",&n) && n){
        if (res[n] != -1){
            printf("%d\n",res[n]);
            continue;
        }
        memset(a, 0, sizeof(a));
        cnt = 0;
        solve(0);
        res[n] = cnt;
        printf("%d\n",cnt);
    }
    return 0;
}
