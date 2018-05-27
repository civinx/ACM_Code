//
//  main.c
//  实验10-3 递归求阶乘和
//
//  Created by czf on 15/9/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

double fact( int n );
double factsum( int n );

int main()
{
    int n;
    
    scanf("%d",&n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));
    
    return 0;
}

double fact( int n ){
    if (n == 0 || n == 1) {
        return 1;
    }
    else{
        return n * fact(n - 1);
    }
}

double factsum( int n ){
    int i;
    double ret = 0;
    for (i = 1; i <=n ; i ++) {
        ret += fact(i);
    }
    return ret;
}