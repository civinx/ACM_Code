//
//  main.cpp
//  HDU 逆袭指数
//
//  Created by czf on 15/12/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 2000;
int res[maxn], temp[maxn];
int maxnum;
void solve(int n, int x, int len){
    if (n%x==0){
        temp[len] = x;
        solve(n/x, x+1, len+1);
    }
    else if(len > maxnum){
        maxnum = len;
        for(int i = 0; i < len; i ++)
            res[i] = temp[i];
    }
}
int main(){
    int n;
    while (scanf("%d",&n) == 1){
        int k = sqrt(n+0.5);
        maxnum = 0;
        for(int i = 2; i <= k; i ++){
            solve(n,i,0);
        }
        if (maxnum == 0){
            maxnum = 1;
            res[0] = n;
        }
        printf("%d\n",maxnum);
        for(int i = 0; i < maxnum; i ++){
            if (i) printf("*");
            printf("%d",res[i]);
        }
        printf("\n");
    }
    return 0;
}
