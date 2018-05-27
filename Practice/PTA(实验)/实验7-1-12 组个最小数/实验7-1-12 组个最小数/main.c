//
//  main.c
//  实验7-1-12 组个最小数
//
//  Created by czf on 15/9/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    const int n = 10;
    int a[n];
    int b[50];

    int num = 0;
    int i;
    int j;
    int k;
    int x;
    int min = 0;
    int temp;
    int sign;
    
    for (i = 0; i < n; i ++) {
        scanf("%d",&a[i]);
    }
    
    for (i = 0; i < n; i ++) {
        num += a[i];
    }
    
    x = 0;
    k = 0;
    for (i = 0; i < n; i ++) {
        for (j = 0; j < a[i]; j ++) {
            b[k] = x;
            k ++;
        }
        x ++;
    }
    
    temp = 0;
    
    for (i = 1; i < num; i ++) {
        if (temp == -1) {
            break;
        }
        for (j = 0; j < num - i; j ++) {
            temp = -1;
            if (b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    
    for (i = 0; i < num; i ++) {
        if (b[i] != 0) {
            min = i;
            sign = i;
            break;
        }
    }
    
    printf("%d",b[min]);
    
    for (i = 0; i < num; i ++) {
        if (i != min) {
            printf("%d",b[i]);
        }
    }
    return 0;
}
