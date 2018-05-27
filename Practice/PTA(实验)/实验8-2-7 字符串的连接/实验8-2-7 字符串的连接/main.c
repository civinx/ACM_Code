//
//  main.c
//  实验8-2-7 字符串的连接
//
//  Created by czf on 15/9/29.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAXS 10

char *str_cat( char *s, char *t );

int main()
{
    char *p;
    char str1[MAXS+MAXS] = {'\0'}, str2[MAXS] = {'\0'};
    
    scanf("%s%s", str1, str2);
    p = str_cat(str1, str2);
    printf("%s\n%s\n", p, str1);
    
    return 0;
}

char *str_cat( char *s, char *t ){
    int i;
    int j;
    j = 0;
    i = 0;
    while (*(s + i) != '\0') {
        i ++;
    }
    while (*(t + j) != '\0') {
        *(s + i + j) = *(t + j);
        j ++;
    }
    return s;
}