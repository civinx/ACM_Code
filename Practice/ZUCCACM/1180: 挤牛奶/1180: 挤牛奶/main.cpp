//
//  main.cpp
//  1180: 挤牛奶
//
//  Created by czf on 15/11/23.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000000 + 5;
int a[maxn];
int main(){
    int n;
    while(scanf("%d",&n) == 1){
        memset(a,0,sizeof(a));
        int maxnum = 0, minnum = maxn;
        while(n--){
            int x, y; scanf("%d%d",&x,&y);
            if(y > maxnum) maxnum = y;
            if(x < minnum) minnum = x;
            for(int i = x; i < y; i ++)
                a[i]++;
        }
        int res_1 = 0, res_2 = 0;
        int k1=0,k2=0;
        for(int i = minnum; i < maxnum; i ++){
            if(a[i] > 0){
                res_1 ++;
                if (res_2>k2){
                    k2 = res_2;
                }
                res_2 = 0;
            }
            else if(a[i] == 0){
                res_2++;
                if (res_1>k1) {
                    k1 = res_1;
                }
                res_1 = 0;
            }
            if (i == maxnum-1){
                if (res_2>k2){
                    k2 = res_2;
                }
                if (res_1>k1) {
                    k1 = res_1;
                }
            }
        }
        printf("%d %d\n",k1,k2);
    }
}