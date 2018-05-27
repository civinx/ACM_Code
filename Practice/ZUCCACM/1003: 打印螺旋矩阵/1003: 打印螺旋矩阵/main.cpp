//
//  main.cpp
//  1003: 打印螺旋矩阵
//
//  Created by czf on 15/11/21.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 10 + 5;
int a[maxn][maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        int n, m, x, y, ans;
        scanf("%d%d",&n,&m);
        a[x=0][y=0] = ans = 1;
        while(ans < n*m){
            while(y+1<m && !a[x][y+1]) a[x][++y] = ++ans;
            while(x+1<n && !a[x+1][y]) a[++x][y] = ++ans;
            while(y-1>=0 && !a[x][y-1]) a[x][--y] = ++ans;
            while(x-1>=0 && !a[x-1][y]) a[--x][y] = ++ans;
        }
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                printf("%2d%c",a[i][j],j==m-1?'\n':' ');
    }
    return 0;
}