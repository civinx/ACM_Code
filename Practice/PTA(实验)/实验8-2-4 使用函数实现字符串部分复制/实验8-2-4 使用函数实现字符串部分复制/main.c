//
//  main.c
//  实验8-2-4 使用函数实现字符串部分复制
//
//  Created by czf on 15/9/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXN 20

void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char t[MAXN], s[MAXN];
    int m;
    int i;
    
    scanf("%d\n", &m);
//    ReadString(t);
    i = 0;
    while ((t[i] = getchar()) != '\n') {
        i ++;
    }
    t[i] = '\0';
    strmcpy( t, m, s );
    printf("%s\n", s);
    
    return 0;
}

void strmcpy( char *t, int m, char *s ){
    int i;
    int j = 0;
    for (i = m - 1; t[i] != '\0'; i ++) {
        s[j] = t[i];
        j ++;
    }
    s[j] = '\0';
}
