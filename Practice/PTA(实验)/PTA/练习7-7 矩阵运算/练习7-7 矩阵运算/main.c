//
//  main.c
//  练习7-7 矩阵运算
//
//  Created by czf on 15/9/19.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a[10][10];
    int n;
    int sum = 0;
    int i,j;
    
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j ++) {
            scanf("%d",&a[i][j]);
        }
    }
    
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j ++) {
            if (i != n - 1 && j != n - 1 && i + j != n - 1) {
                sum += a[i][j];
            }
        }
    }
    
    printf("%d",sum);
    return 0;
}
