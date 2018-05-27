//
//  main.cpp
//  1005 Number Sequence
//
//  Created by czf on 15/11/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 10000 + 5;
int num[maxn] = {0,1,1};
int main(){
    int a, b, n;
    while(scanf("%d%d%d",&a,&b,&n) == 3 && n){
        for(int i = 3; i <= n; i ++)
            num[i] = (num[i-1]*a + num[i-2]*b) % 7;
        for (int i = 1; i <= n; i ++) {
            printf("%d %d\n",i,num[i]);
        }
    }
}