//
//  main.c
//  习题7-2 求一批整数中出现最多的个位数字
//
//  Created by czf on 15/9/18.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int i;
    int max;
    int k; //提取出的数字
    int x; //输入的数字
    int n; //数字个数
    
    int a[10]; //储存0-1的个数 每个格子的大小就是每个数的多少
    for (i = 0; i < 10; i ++) {
        a[i] = 0;
    }
    
    scanf("%d",&n);
    for (i = 0; i < n; i ++) {
        scanf("%d",&x);
        while (x != 0) {
            k = x % 10;
            a[k] ++;
            x /= 10;
        }
    }
    max = 0;
    for (i = 1; i < 10; i ++) {
        
        if (a[i] > a[max]) {
            max = i;
        }
    }
    
    printf("%d:",a[max]);
    
    for (i = max; i <10; i ++) {
        if (a[i] == a[max]) {
            printf(" %d",i);
        }
    }
    return 0;
}
