//
//  main.c
//  实验7-3-6 字符串转换成十进制整数
//
//  Created by czf on 15/9/24.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char str[81];
    char new[81];
    int i,k;
    long num;
    int sign = 0;
    i = 0;
    while ((str[i] = getchar()) != '#') {
        i ++;
    }
    str[i] = '\0';
    
    k = 0;
    for (i = 0; str[i] != '\0'; i ++) {
        if ((str[i] >= '0' && str[i] <= '9')||(str[i] >= 'a' && str[i] <= 'f')||(str[i] >= 'A' && str[i] <= 'F')||(str[i] == '-')) {
            new[k] = str[i];
            k ++;
        }
        if (new[0] == '-'){
            sign = -1;
        }
    }
    new[k] = '\0';
    
    num = 0;
    for (i = 0; new[i] != '\0'; i++) {
        if (new[i]<='9' && new[i] >= '0') {
            num = num * 16 + new[i] - '0';
        }
        
        else if(new[i]<='F' && new[i] >= 'A'){
            num = num * 16 + new[i] - 'A' + 10;
        }
        else if(new[i]<='f' && new[i] >= 'a'){
            num = num * 16 + new[i] - 'a' + 10;
        }
    }
    if (sign == -1) {
        num *= sign;
    }
    
    printf("%ld",num);
    return 0;
}