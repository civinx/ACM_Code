//
//  main.c
//  实验4-2-2 求e的近似值
//
//  Created by czf on 15/9/21.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

double jiecheng(int n);

int main() {
    int i;
    int n;
    double sum;
    
    scanf("%d",&n);
    
    sum = 1;
    
    for (i = 1; i <= n ; i ++) {
        sum += 1/jiecheng(i);
    }
    
    printf("%.8f",sum);
    return 0;
}

double jiecheng(int n){
    int i;
    double sum = 1;
    for (i = 1; i <= n; i ++) {
        sum *= i;
    }
    return sum;
}