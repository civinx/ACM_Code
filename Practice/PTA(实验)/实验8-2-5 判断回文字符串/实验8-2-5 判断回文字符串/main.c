//
//  main.c
//  实验8-2-5 判断回文字符串
//
//  Created by czf on 15/9/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAXN 20
typedef enum {false, true} bool;

bool palindrome( char *s );

int main()
{
    char s[MAXN];
    
    scanf("%s", s);
    if ( palindrome(s)==true )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n", s);
    
    return 0;
}

bool palindrome( char *s ){
    bool ret;
    int i;
    int j = 0;
    
    for (i = 0; s[i] != '\0'; i ++) {
        j = i;
    }
    i = 0;
    while (i < j) {
        if (s[i] != s[j]) {
            break;
        }
        i ++;
        j --;
    }
    if (j <= i) {
        ret = true;
    }
    else{
        ret = false;
    }
    return ret;
}
