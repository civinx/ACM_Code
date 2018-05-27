//
//  main.cpp
//  1215: 穿越通道
//
//  Created by czf on 15/11/11.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int a[maxn][maxn];
int d[maxn][maxn];
int n, m;

void read(){
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            scanf("%d",&a[i][j]);
        }
    }
}

int solve(int x, int y){
    if (x>=n || y>=m) return 2147483647;
    if (d[x][y] >= 0) return d[x][y];
    return d[x][y] = a[x][y] + (x==n-1&&y==m-1 ? 0:min(solve(x+1, y),solve(x, y+1)));
}

int main() {
    while (scanf("%d%d",&n,&m) == 2) {
        read();
        memset(d, -1, sizeof(d));
        solve(0, 0);
        printf("%d\n",d[0][0]);
    }
    return 0;
}
