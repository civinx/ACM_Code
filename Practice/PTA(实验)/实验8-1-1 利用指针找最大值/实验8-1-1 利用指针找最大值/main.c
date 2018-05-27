//
//  main.c
//  实验8-1-1 利用指针找最大值
//
//  Created by czf on 15/9/25.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

void findmax( int *px, int *py, int *pmax );

int main()
{
    int max, x, y;
    
    scanf("%d %d", &x, &y);
    findmax( &x, &y, &max );
    printf("%d\n", max);
    
    return 0;
}

void findmax( int *px, int *py, int *pmax ){
    int max;
    max = *px;
    
    if (*py > max) {
        max = *py;
    }
    
    *pmax = max;
}