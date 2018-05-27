//
//  main.c
//  实验11-1-6 指定位置输出字符串
//
//  Created by czf on 15/10/2.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;
    
    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);
    
    return 0;
}

char *match( char *s, char ch1, char ch2 ){
    int i;
    int j = 0;
    int flag = 0;
    i = 0;
    int k;
    char ch;
    ch = ' ';
    char out[MAXS];
    
    while (s[i] != '\0') {
        if (s[i] == ch1) {
            flag = 1;
            k = i;
            for (; s[i] != '\0'; i ++) {
                out[j] = s[i];
                j ++;
                if (s[i] == ch2 || s[i + 1] == '\0') {
                    out[j] = '\0';
                    break;
                }
            }
            break;
        }
        else{
            i ++;
        }
    }
    if (flag) {
        printf("%s\n",out);
        return s + k;
    }
    printf("\n");
    return &ch;
}
