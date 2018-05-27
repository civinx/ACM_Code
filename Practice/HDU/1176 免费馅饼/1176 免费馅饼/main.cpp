//
//  main.cpp
//  1176 免费馅饼
//
//  Created by czf on 15/12/28.
//  Copyright © 2015年 czf. All rights reserved.
//
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mymax(a,b,c) max(max(a,b),c)
using namespace std;
const int maxn = 110000;
int a[maxn][15], dp[maxn][15], T;

int main(){
    int n;
    while(scanf("%d",&n) && n){
        int temp = n;
        T = 0;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        while(temp--){
            int x, t; scanf("%d%d",&x,&t);
            a[t][x] ++;
            if (t > T) T = t;
        }
        for(int i = T-1; i >= 0; i --){
            a[i][0] = max(a[i+1][0],a[i+1][1])+a[i][0];
            a[i][10] = max(a[i+1][9],a[i+1][10])+a[i][10];
            for(int j = 1; j < 10; j ++){
                a[i][j] = mymax(a[i+1][j-1],a[i+1][j],a[i+1][j+1])+a[i][j];
            }
        }
        printf("%d\n",a[0][5]);
    }
    return 0;
}