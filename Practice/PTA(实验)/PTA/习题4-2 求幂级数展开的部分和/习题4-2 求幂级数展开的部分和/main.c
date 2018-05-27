//
//  main.c
//  习题4-2 求幂级数展开的部分和
//
//  Created by czf on 15/9/16.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main() {
    double sum = 1;
    int k = 1;
    int i;
    double jiecheng;
    double x;
    
    scanf("%lf",&x);
    do{
        jiecheng = 1;
        for (i = 1; i <= k; i ++) {
            jiecheng *= i;
        }
        sum += pow(x, k)/jiecheng;
        k ++;
        
    }while ((pow(x, k)/jiecheng) >= 0.00001);
    printf("%.4f",sum);
    return 0;
}
