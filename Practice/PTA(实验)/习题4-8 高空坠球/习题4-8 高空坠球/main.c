//
//  main.c
//  习题4-8 高空坠球
//
//  Created by czf on 15/9/16.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main(){
    double h,n;
    double s1,s2;
    int i;
    scanf("%lf%lf",&h,&n);
    
    s1 = h;
    s2 = 0;
    
    for (i = 1; i < n; i ++) {
        s1 += (h / pow(2, i)) * 2;
    }
    
    s2 = h / pow(2, n);
    
    if (n == 0) {
        s1 = s2 = 0;
    }
    
    printf("%.1lf %.1lf",s1,s2);
    
    return 0;
}