//
//  main.c
//  练习7-3 将数组中的数逆序存放
//
//  Created by czf on 15/9/17.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int num;
    scanf("%d",&num);
    int a[num];
    int i;
    int x;
    
    for (i = 0; i < num; i ++) {
        scanf("%d",&x);
        a[i] = x;
    }
    for (i = i - 1; i >= 0; i --) {
        printf("%d",a[i]);
        if (i != 0) {
            printf(" ");
        }
    }
    return 0;
}
