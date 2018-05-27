//
//  main.c
//  实验7-2-1 求矩阵各行元素之和
//
//  Created by czf on 15/9/23.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a[6][6];
    int x,y;
    int i,j;
    int sum;
    
    scanf("%d%d",&x,&y);
    
    for (i = 0; i < x; i ++) {
        for (j = 0; j < y; j ++) {
            scanf("%d",&a[i][j]);
        }
    }
    
    for (i = 0; i < x; i ++) {
        sum = 0;
        for (j = 0; j < y; j ++) {
            sum += a[i][j];
        }
        printf("%d\n",sum);
    }
    
    return 0;
}
