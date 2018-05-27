//
//  main.c
//  实验8-1-6 函数实现字符串逆序
//
//  Created by czf on 15/9/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXS 20

void f( char *p );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];
    int i;
    
    i = 0;
    while ((s[i] = getchar()) != '\n') {
        i ++;
    }
    s[i] = '\0';
    
    f(s);
    printf("%s\n", s);
    
    return 0;
}

void f( char *p ){
    int i;
    int max = 0;
    char temp;
    for (i = 0; p[i] != '\0'; i ++) {
        max = i;
    }
    for (i = 0; i <= max / 2; i ++) {
        temp = p[i];
        p[i] = p[max - i];
        p[max - i] = temp;
    }
}
