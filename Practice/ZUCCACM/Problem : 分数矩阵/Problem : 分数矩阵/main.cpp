//
//  main.cpp
//  Problem : 分数矩阵
//
//  Created by czf on 15/11/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    int n;
    while(scanf("%d",&n) && n){
        double sum = 0;
        for(double i = 2; i <= n; i ++){
            sum += (1/i) * (n+1-i);
        }
        sum = sum*2 + n;
        printf("%.2f\n",sum);
    }
}