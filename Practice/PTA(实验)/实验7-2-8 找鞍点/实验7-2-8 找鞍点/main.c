//
//  main.c
//  实验7-2-8 找鞍点
//
//  Created by czf on 15/9/23.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    int a[6][6];
    int b[6];
    int c[6];
    int n;
    int i,j,k;
    int min_i;
    int max_j;
    int cnt_i = 0;
    int cnt_j = 0;
    int flag = 0;
    
    scanf("%d",&n);
    
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j ++) {
            scanf("%d",&a[i][j]);
        }
    }                                   //读取数组

    for (i = 0; i < n; i ++) {
        max_j = 0;
        cnt_i = 0;
        cnt_j = 0;
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));        //每行一轮 初始化
        for (j = 0; j < n; j ++) {
            if (a[i][j] > a[i][max_j]) {
                max_j = j;
            }
        }                               //判断出每行最大的数
        for (j = 0; j < n; j ++) {
            if (a[i][j] == a[i][max_j]) {
                b[cnt_j] = j;           //b数组中存放最大的数哪几列 cnt_j为最大的数的个数
                cnt_j ++;
            }
        }
        for (k = 0; k < cnt_j; k ++) {  //每个最大的数的列数循环一轮 次数为最大的数的个数
            min_i = 0;
            max_j = b[k];               //每一轮赋值一个最大的数的列数
            for (j = 0; j < n; j ++) {
                if (a[j][max_j] < a[min_i][max_j]) {
                    min_i = j;          //判断该列最小的数
                }
            }
    
            for (j = 0; j < n; j ++) {
                if (a[j][max_j] == a[min_i][max_j]) {
                    c[cnt_i] = j;       //c数组存放最小的数在哪几行 cnt_i为该列最小的数的个数
                    cnt_i ++;
                }
            }
            
            for (j = 0; j < cnt_i; j ++) { //遍历c数组 如果有最小的数的行数=该大循环i的行数 即
                if (c[j] == i) {            //该列最小的数的行数=该行最大的数的行数 即鞍点
                    printf("%d %d",c[j],max_j);//输出该行数 该列数
                    flag = 1;
                }
            }
        }
    }
    if (flag == 0) {
        printf("NONE");
    }
    return 0;
}
