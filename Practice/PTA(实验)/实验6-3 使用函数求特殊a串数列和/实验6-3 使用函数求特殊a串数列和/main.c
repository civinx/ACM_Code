//
//  main.c
//  实验6-3 使用函数求特殊a串数列和
//
//  Created by czf on 15/9/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int fn( int a, int n );
int SumA( int a, int n );

int main()
{
    int a, n;
    
    scanf("%d %d", &a, &n);
    printf("fn(%d, %d) = %d\n", a, n, fn(a,n));
    printf("s = %d\n", SumA(a,n));
				
    return 0;
}

int fn( int a, int n ){
    int ret = 0;
    int i;
    int mask = 1;
    
    
    for (i = 1; i < n; i ++) {
        mask *= 10;
    }
    for (i = 1; i <= mask; i *= 10) {
        ret += a * i;
    }
    
    return ret;
}

int SumA( int a, int n ){
    int i;
    int sum = 0;
    
    for (i = 1; i <= n; i ++) {
        sum += fn(a, i);
    }
    return sum;
}