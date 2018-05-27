//
//  main.c
//  实验7-1-11 求整数序列中出现次数最多的数
//
//  Created by czf on 15/9/22.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    
    int a[1000];
    int b[1000];
    int n;
    int i,j;
    int max;
    memset(b, 0, sizeof(b));
    
    scanf("%d",&n);
    
    for (i = 0; i < n; i ++) {
        scanf("%d",&a[i]);
    }
    
    for (i = 0; i < n; i ++) {
        for (j = 0; j < n; j ++) {
            if (a[i] == a[j]) {
                b[i] ++;
            }
        }
    }
    
    max = b[0];
    j = 0;
    for (i = 1; i < n; i ++) {
        if (b[i] > max) {
            max = b[i];
            j = i;
        }
    }
    
    printf("%d %d",a[j],max);
    
    return 0;
}
