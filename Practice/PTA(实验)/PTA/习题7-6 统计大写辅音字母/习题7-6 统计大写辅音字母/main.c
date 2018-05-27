//
//  main.c
//  习题7-6 统计大写辅音字母
//
//  Created by czf on 15/9/17.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char str[80];
    int i;
    int cnt;
    
    i = 0;
    while ((str[i] = getchar()) != '\n') {
        i ++;
    }
    str[i] = '\0';
    
    cnt = 0;
    for (i = 0; str[i] != '\0'; i ++) {
        if (str[i]<= 'Z' && str[i] >= 'B' && str[i] != 'E' &&str[i] != 'I'&&str[i] != 'O'&&str[i] != 'U') {
            cnt ++;
        }
    }
    
    printf("%d",cnt);
    
    return 0;
}
