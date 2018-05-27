//
//  main.c
//  实验7-3-10 删除重复字符
//
//  Created by czf on 15/9/23.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include<stdio.h>
#include<string.h>
int main(){
    
    char a[80];
    int b[256] = {0};
    int i;
    
    i = 0;
    while ((a[i] = getchar()) != '\n') {
        i ++;
    }
    a[i] = '\0';
    
    for (i = 0; a[i] != '\0'; i ++) {
        b[a[i]] = 1;
    }
    
    for (i = 0; i < 256; i ++) {
        if (b[i] == 1) {
            printf("%c",i);
        }
    }
    return 0;
}
