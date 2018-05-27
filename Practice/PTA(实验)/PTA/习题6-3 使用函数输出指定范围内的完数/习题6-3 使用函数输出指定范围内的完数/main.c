//
//  main.c
//  习题6-3 使用函数输出指定范围内的完数
//
//  Created by czf on 15/9/16.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int factorsum( int number );
void PrintPN( int m, int n );

int main()
{
    int i, m, n;
    
    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);
    
    return 0;
}

int factorsum( int number ){
    int sum = 0;
    int i;
    for (i = 1; i < number; i ++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    if (number == 1) {
        sum = 1;
    }
    return sum;
}

void PrintPN( int m, int n ){
    int i;
    int k;
    int ret = 0;
    for (i = m; i <= n; i ++) {
        if (factorsum(i) == i) {
            ret = 1;
            printf("%d = ",i);
            if (i == 1) {
                printf("1");
            }
            for (k = 1; k < i; k++) {
                if (i % k == 0) {
                    if (k != 1) {
                        printf(" + ");
                    }
                    printf("%d",k);
                }
            }
            printf("\n");
        }
        
    }
    if (ret == 0) {
        printf("No perfect number");
    }
}