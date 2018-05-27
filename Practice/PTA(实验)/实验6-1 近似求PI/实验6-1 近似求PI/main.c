//
//  main.c
//  实验6-1 近似求PI
//
//  Created by czf on 15/9/25.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

double jiecheng(double x);

int main() {
    
    double result = 1;
    double eps;
    double fenmu = 1 ;
    double i;
    double j;
    
    scanf("%le", &eps);
    
    for (j = 1; jiecheng(j-1)/fenmu >= eps; j ++) {
        fenmu = 1;
        for (i = 3; i <= 2 * j + 1; i += 2) {
            fenmu *= i;
        }
        result += jiecheng(j)/fenmu;
    }
    
    printf("PI = %.5lf",result * 2);
    
    return 0;
}
double jiecheng(double x){
    double ret = 1;
    int i;
    
    for (i = 1; i <= x; i ++) {
        ret *= i;
    }
    
    return ret;
}