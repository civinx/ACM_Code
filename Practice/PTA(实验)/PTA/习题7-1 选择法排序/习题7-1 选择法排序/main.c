//
//  main.c
//  习题7-1 选择法排序
//
//  Created by czf on 15/9/18.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a[10];
    int temp;
    int max;
    int i;
    int k;
    int n;
    
    scanf("%d",&n);
    for (i = 0; i < n; i ++) {
        scanf("%d",&a[i]);
    }
    
    for (k = 0; k < n - 1; k ++) {  //最后一个数不用管 所以n - 1
        max = k;
        for (i = k + 1; i < n; i ++) {
            if (a[i] > a[max]) {
                max = i;
            }
        }
        temp = a[k];
        a[k] = a[max];
        a[max] = temp;
    }
    
    for (i = 0; i < n; i ++) {
        printf("%d",a[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    return 0;
}
