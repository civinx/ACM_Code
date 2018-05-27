//
//  main.c
//  练习7-8 方阵循环右移
//
//  Created by czf on 15/9/19.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a[10][10];
    int m;
    int n;
    int i,j;
    int k;
    
    scanf("%d%d",&m,&n);
    if (m > n) {
        m %= n;
    }
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j ++) {
            scanf("%d",&a[i][j]);
        }
    }
    
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j ++) {
            k = j;
            if (k >= 0 && k < m) {
                k = n - m + k;
            }
            else{
                k = k - m;
            }
            if (m != 0) {
                printf("%d ",a[i][k]);
            }
            else{
                printf("%d ",a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
