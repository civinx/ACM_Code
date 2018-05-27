//
//  main.c
//  实验8-1-5 在数组中查找指定元素
//
//  Created by czf on 15/9/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXN 10

int search( int list[], int n, int x );

int main()
{
    int i, index, n, x;
    int a[MAXN];
    
    scanf("%d", &n);
    for( i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    scanf("%d", &x);
    index = search( a, n, x );
    if( index != -1 )
        printf("index = %d\n", index);
    else
        printf("Not found\n");
    
    return 0;
}

int search( int list[], int n , int x){
    int ret = -1;
    int i;
    for (i = 0; i < n; i ++) {
        if (list[i] == x) {
            ret = i;
            break;
        }
    }
    return ret;
}
