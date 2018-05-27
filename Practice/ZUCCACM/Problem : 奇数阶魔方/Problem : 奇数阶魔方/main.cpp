//
//  main.cpp
//  Problem : 奇数阶魔方
//
//  Created by czf on 15/10/28.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int maxn = 20;
int a[maxn][maxn];
int flag[maxn][maxn];

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(flag, 0, sizeof(flag));
        int n;
        int ans = 1;
        scanf("%d",&n);
        int i = 1, j = n/2+1;
        while (ans <= n*n) {
            a[i][j] = ans;
            flag[i][j] = 1;
            if (i == 1 && j != n) { //第一行非最后一列
                i = n; j ++;
            }
            else if (i == 1 && j == n){//第一行最后一列
                i ++;
            }
            else if (j == n){//最后一列非第一行
                i --; j = 1;
            }
            else if (!flag[i-1][j+1]){
                i --; j ++;
            }
            else{
                i ++;
            }
            ans ++;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                printf("%4d",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
