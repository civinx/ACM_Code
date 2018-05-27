//
//  main.c
//  实验7-3-2 查找指定字符
//
//  Created by czf on 15/9/24.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char a[81];
    char x;
    int i;
    int flag = 0;
    int index = 0;
    
    scanf("%c",&x);
    
    getchar();
    
    i = 0;
    while ((a[i] = getchar()) != '\n') {
        i ++;
    }
    a[i] = '\0';
    
    
    for (i = 0; a[i] != '\0'; i ++) {
        if (a[i] == x) {
            flag = 1;
            index = i;
        }
    }
    
    if (flag == 1) {
        printf("index = %d",index);
    }
    else{
        printf("Not Found");
    }
    return 0;
}
