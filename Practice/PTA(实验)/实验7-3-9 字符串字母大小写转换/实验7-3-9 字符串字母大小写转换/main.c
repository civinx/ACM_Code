//
//  main.c
//  实验7-3-9 字符串字母大小写转换
//
//  Created by czf on 15/9/24.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char a[31];
    int i;
    
    i = 0;
    while ((a[i] = getchar()) != '#') {
        i ++;
    }
    a[i] = '\0';
    
    for (i = 0; a[i] != '\0'; i ++) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            a[i] = a[i] - 'a' + 'A';
        }
        else if (a[i] >= 'A' && a[i] <= 'Z'){
            a[i] = a[i] - 'A' + 'a';
        }
    }
    
    for (i = 0; a[i] != '\0'; i ++) {
        printf("%c",a[i]);
    }
    return 0;
}
