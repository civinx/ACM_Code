//
//  main.c
//  实验8-1-7 数组循环右移
//
//  Created by czf on 15/9/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXN 10

int ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;
    
    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);
    
    ArrayShift(a, n, m);
    
    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    
    return 0;
}

int ArrayShift( int a[], int n, int m ){
    int b[MAXN];
    for (int i = 0; i < n; i ++) {
        b[i] = a[i];
    }
    for (int i = 0; i < n; i ++) {
        a[(i+m)%n] = b[i];
    }
    return *a;
}