//
//  main.c
//  实验7-2-9 螺旋方阵
//
//  Created by czf on 15/9/24.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int a[10][10];

void luoxuan(int left, int right, int up, int down, int v, int n);

int main() {
    
    int n;
    scanf("%d",&n);
    
    luoxuan(0, n - 1, 0, n - 1, 1, n);
    
    return 0;
}

void luoxuan(int left, int right, int up, int down, int v, int n){
    int x,y,k,m;
    int i,j;
    if (left <= right) {
        for (x = left; x <= right; x ++) {
            a[up][x] = v;
            v ++;
        }
        for (y = up + 1; y < down; y ++) {
            a[y][right] = v;
            v ++;
        }
        for (k = right; k > left; k --){
            a[down][k] = v;
            v ++;
        }
        for (m = down ; m > up; m --) {
            a[m][left] = v;
            v ++;
        }
        luoxuan(left + 1, right - 1, up + 1, down - 1, v, n);
    }
    else{
        for (i = 0; i < n; i ++) {
            for (j = 0; j < n; j ++) {
                printf("%3.d",a[i][j]);
            }
            printf("\n");
        }
    }
}