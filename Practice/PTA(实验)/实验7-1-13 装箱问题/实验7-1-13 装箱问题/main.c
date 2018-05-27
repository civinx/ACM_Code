//
//  main.c
//  实验7-1-13 装箱问题
//
//  Created by czf on 15/9/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    const int v = 100;
    int object_n = 0;
    int max;
    int i,j;
    int a[1000];
    int b[1000];
    
    scanf("%d",&object_n);
    
    for (i = 0; i < object_n; i ++) {
        b[i] = v;
    }
    for (i = 0; i < object_n; i ++) {
        scanf("%d",&a[i]);
    }
    
    max = 0;
    
    for (i = 0; i < object_n; i ++) {
        for (j = 0; j < object_n; j ++) {
            if (a[i] <= b[j]) {
                if (j > max) {
                    max = j;
                }
                b[j] -= a[i];
                printf("%d %d\n",a[i],j + 1);
                break;
            }
        }
    }
    
    printf("%d",max + 1);
    
    return 0;
}
