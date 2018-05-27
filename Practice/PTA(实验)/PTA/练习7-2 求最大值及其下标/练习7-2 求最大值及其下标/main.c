//
//  main.c
//  练习7-2 求最大值及其下标
//
//  Created by czf on 15/9/17.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d",&num);
    int a[num];
    int max;
    int sign = 0;
    int i;
    int x;
    
    for (i = 0; i < num; i ++) {
        scanf("%d",&x);
        a[i] = x;
    }
    max = a[0];
    for (i = 0; i < num; i ++) {
        if (a[i] > max) {
            max = a[i];
            sign = i;
        }
    }
    printf("%d %d",max,sign);
    return 0;
}
