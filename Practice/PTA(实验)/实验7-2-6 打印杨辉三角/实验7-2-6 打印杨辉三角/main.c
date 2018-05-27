//
//  main.c
//  实验7-2-6 打印杨辉三角
//
//  Created by czf on 15/9/21.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a[10][10];
    int i,j,k;
    int n;
    
    a[0][0] = 1;
    a[1][0] = 1;
    a[1][1] = 1;  //初始前两行全为1
    
    scanf("%d",&n);
    
    for (i = 2; i < n; i ++) {
        a[i][i] = 1;                //杨辉三角每行的个数与行数相等 所以第i行的第i个为最后一个
        a[i][0] = 1;                //让杨辉三角每行的第一个和最后一个都为1
    }
    
    for (i = 2; i < n; i ++) {
        for (j = 1; j < i; j ++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1]; //给除了1已外的数字赋值，第i行j列的数字等于
    }                                                //第i-1行第j列 + 第i-1行第j-1列
    }
    
   for (i = 0; i < n; i ++) {
        for (k = 0; k < n - 1 - i; k ++) {
            printf(" ");                      //若行数是n-1 最后一行输出0(n - 1 -(n - 1))个空格
        }                                     //第0行输出n - 1 - 0个空格
        for (j = 0; j <= i; j ++) {
            printf("%4d",a[i][j]);              //题目要求每个数字占4格 遍历数组输出
        }
        printf("\n");                       //每行完成后换行
    }
    return 0;
}
