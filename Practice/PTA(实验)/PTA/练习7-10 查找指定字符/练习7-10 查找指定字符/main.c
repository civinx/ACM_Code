//
//  main.c
//  练习7-10 查找指定字符
//
//  Created by czf on 15/9/17.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char str[80];
    int i;
    char need;
    int sign = -1;
    
    scanf("%c",&need);
    i = 0;
    getchar(); //这样就可以敲回车了！！！
    while ((str[i] = getchar()) != '\n') {
        i ++;
    }
    str[i] = '\0';
    
    for (i = 0; str[i] != '\0'; i ++) {
        if (str[i] == need) {
            sign = i;
        }
    }
    if (sign == -1) {
        printf("Not Found");
    }
    else{
        printf("index = %d", sign);
    }
    return 0;
}
