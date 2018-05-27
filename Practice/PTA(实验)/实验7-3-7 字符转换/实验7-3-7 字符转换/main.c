//
//  main.c
//  实验7-3-7 字符转换
//
//  Created by czf on 15/9/24.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char a[81];
    int cnt = 0;
    int mask = 1;
    int i;
    double result = 0;
    
    i = 0;
    while ((a[i] = getchar()) != '\n') {
        i ++;
    }
    a[i] = '\0';
    
    for (i = 0; a[i] != '\0'; i ++) {
        if (a[i] >= '0' && a[i] <= '9') {
            cnt ++;
        }
    }
    
    for (i = 1; i < cnt; i ++) {
        mask *= 10;
    }
    
    for (i = 0; a[i] != '\0'; i ++) {
        if (a[i] >= '0' && a[i] <= '9') {
            result += (a[i] - '0') * mask;
            mask /= 10;
        }
    }
    
    printf("%.lf",result);
    
    return 0;
}
