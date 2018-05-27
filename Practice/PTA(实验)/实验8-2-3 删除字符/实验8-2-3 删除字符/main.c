//
//  main.c
//  实验8-2-3 删除字符
//
//  Created by czf on 15/9/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXN 20

void delchar( char *str, char c );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char str[MAXN], c;
    int i;
    
    scanf("%c\n", &c);
    
    i = 0;
    while ((str[i] = getchar()) != '\n') {
        i ++;
    }
    str[i] = '\0';
    
  
    delchar(str, c);
    printf("%s\n", str);
    
    return 0;
}

void delchar( char *str, char c ){
    int i;
    int j;
    for (i = 0; str[i] != '\0'; ) {
        if (str[i] == c) {
            for (j = i ; str[j] != '\0'; j ++) {
                str[j] = str[j + 1];
            }
        }
        else{
            i ++;
        }
    }
}
