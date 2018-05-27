//
//  main.c
//  实验7-1-1 简化的插入排序
//
//  Created by czf on 15/9/21.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a[10];
    int n;
    int i;
    int temp;
    int rongqi;
    
    scanf("%d",&n);
    
    for (i = 0; i <= n; i ++) {
        scanf("%d",&a[i]);
    }
    
    temp = n;
    
    for (i = 0; i <= n; i ++) {
        if (a[temp] <= a[i]) {
            temp = i;
            break;
        }
    }
    
    rongqi = a[n];
    
    for (i = n ; i != temp ; i --) {
        a[i] = a[i - 1];
    }
    
    a[temp] = rongqi;
    
    for (i = 0; i <= n; i ++) {
        printf("%d ",a[i]);
    }
    return 0;
}
