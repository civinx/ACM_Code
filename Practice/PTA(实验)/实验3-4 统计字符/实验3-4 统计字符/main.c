//
//  main.c
//  实验3-4 统计字符
//
//  Created by czf on 15/9/22.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char str[11];
    int i;
    int letter = 0;
    int blank = 0;
    int digit = 0;
    int other = 0;
    
    
    for (i = 0; i < 10; i ++) {
        str[i] = getchar();
    }
    
    str[i] = '\0';
    
    for (i = 0; str[i] != '\0'; i ++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            letter ++;
        }
        else if (str[i] >= '0' && str[i] <= '9'){
            digit ++;
        }
        else if (str[i] == ' ' || str[i] == '\n'){
            blank ++;
        }
        else{
            other ++;
        }
    }
    
    printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
    
    return 0;
}
