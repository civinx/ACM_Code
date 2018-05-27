//
//  main.c
//  实验7-1-10 交换最小值和最大值
//
//  Created by czf on 15/9/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(){
    int a[10];
    int i;
    int n;
    int max;
    int min;
    int rongqi;
    
    scanf("%d",&n);
    for (i = 0; i < n; i ++) {
        scanf("%d",&a[i]);
    }
    
    
    min = 0;
    
    for (i = 1; i < n; i ++) {
        if (a[i] < a[min]) {
            min = i;
        }
    }
    
    rongqi = a[min];
    a[min] = a[0];
    a[0] = rongqi;
    
    max = 0;
    
    for (i = 1; i < n; i ++) {
        if (a[i] > a[max]) {
            max = i;
        }
    }

    rongqi = a[max];
    a[max] = a[n - 1];
    a[n - 1] = rongqi;
    
    for (i = 0; i < n; i ++) {
        printf("%d ",a[i]);
    }
    return 0;
}
