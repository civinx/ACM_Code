//
//  main.c
//  实验11-1-8 查找子串
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;
    
    gets(s);
    gets(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%ld\n", pos - s);
    else
        printf("-1\n");
    
    return 0;
}

char *search(char *s, char *t){
    unsigned int i = 0;
    if ( *s == 0 ) // 如果字符串s为空
    {
        if ( *t ) // 如果字符串t不为空
            return (char*)NULL; // 则返回NULL
        return (char*)s; // 如果t也为空，则返回s
    }
    
    
    while ( *s ) // 串s没有结束
    {
        i = 0;
        while ( 1 )
        {
            if ( t[i] == 0 )
            {
                return (char*)s;
            }
            if ( t[i] != s[i] )
                break;
            i++;
        }
        s++;
    }
    return (char*)NULL;
}
