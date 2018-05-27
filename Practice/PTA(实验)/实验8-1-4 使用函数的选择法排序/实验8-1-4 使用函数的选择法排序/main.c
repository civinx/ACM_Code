//
//  main.c
//  实验8-1-4 使用函数的选择法排序
//
//  Created by czf on 15/9/25.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXN 10

void sort( int a[], int n );

int main()
{
    int i, n;
    int a[MAXN];
    
    scanf("%d", &n);
    for( i=0; i<n; i++ )
        scanf("%d", &a[i]);
    
    sort(a, n);
    
    printf("After sorted the array is:");
    for( i = 0; i < n; i++ )
        printf(" %d", a[i]);
    printf("\n");
    
    return 0;
}

void sort( int a[], int n ){
    int i,j;
    int t;
    for (i = 1; i < n; i ++) {
        for (j = 0; j < n - i; j ++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
