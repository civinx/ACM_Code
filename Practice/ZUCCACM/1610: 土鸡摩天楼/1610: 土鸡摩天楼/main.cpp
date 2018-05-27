//
//  main.cpp
//  1610: 土鸡摩天楼
//
//  Created by czf on 15/12/21.
//  Copyright © 2015年 czf. All rights reserved.
//


#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int num[10][7] = {{1,1,1,1,1,1,0},{0,0,1,1,0,0,0},{0,1,1,0,1,1,1},{0,1,1,1,1,0,1},{1,0,1,1,0,0,1},
				{1,1,0,1,1,0,1},{1,1,0,1,1,1,1},{0,1,1,1,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,1,0,1}};
int ans[10][8];
int main(){
    int dfr;
    memset(ans,0,sizeof(ans));
    for(int i = 0; i < 10; i ++){
        for(int j = 0; j <= 7; j ++){//坏的灯数
            for(int k = 0; k < 10; k ++){
                dfr = 0;
                for(int m = 0; m < 7; m ++){
                    if (num[i][m] != num[k][m]) dfr ++;
                }
                if (j >= dfr) ans[i][j] ++;
            }
        }
    }
    int t; scanf("%d",&t);
    while(t--){
        int n, k; scanf("%d%d",&n,&k);
        string s; cin >> s;
        int res = 1;
        for(int i = 0; i < n; i ++){
            res *= ans[s[i]-'0'][k];
        }
        printf("%d\n",res);
    }
    return 0;
}