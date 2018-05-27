//
//  main.c
//  实验7-1-6 求一批整数中出现最多的个位数字
//
//  Created by czf on 15/9/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a[10];
    int i;
    int n;
    int x;
    int max;
    
    for (i = 0; i < 10; i ++) {
        a[i] = 0;
    }
    
    scanf("%d",&n);
    
    for (i = 0; i < n; i ++) {
        scanf("%d",&x);
        while (x != 0) {
            a[x % 10] ++;
            x /= 10;
        }
    }
    
    max = 0;
    
    for (i = 0; i < 10; i ++) {
        if (a[i] > a[max]) {
            max = i;
        }
    }
    
    printf("%d:",a[max]);
    
    for (i = 0; i < 10; i ++) {
        if (a[i] == a[max]) {
            printf(" %d",i);
        }
    }
    return 0;
}
