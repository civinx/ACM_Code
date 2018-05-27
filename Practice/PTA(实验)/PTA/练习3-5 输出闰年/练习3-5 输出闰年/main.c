//
//  main.c
//  练习3-5 输出闰年
//
//  Created by czf on 15/9/16.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int year;
    int i;
    int ret = 0;
    scanf("%d",&year);
    if (year <= 2000 || year >2100) {
        printf("Invalid year!");
        ret = 1;
    }
    else{
        for (i = 2001; i <= year; i ++) {
            if (i % 4 == 0 && i % 100 != 0) {
                printf("%d\n",i);
                ret = 1;
            }
        }
    }
    if (ret == 0) {
        printf("None");
    }
    return 0;
}
