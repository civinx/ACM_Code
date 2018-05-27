//
//  main.c
//  实验8-2-9 长整数转化成16进制字符串
//
//  Created by czf on 15/10/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXN 10

void f( long int x, char *p );

int main()
{
    long int x;
    char s[MAXN] = "";
    
    scanf("%ld", &x);
    f(x, s);
    printf("%s\n", s);
    
    return 0;
}

void f( long int x, char *p ){
    int n;
    int j;
    int i = 0;
    char temp;
    int sign = 1;
    if (x < 0) {
        x = -x;
        sign = -1;
    }
    if (x == 0) {
        *p = '0';
        *(p + 1) = '\0';
    }
    else{
        while (x > 0) {
            n = x % 16;
            if (n < 10){
                *(p + i) = n + '0';
            }
            else{
                *(p + i) = 'A' + n - 10;
            }
            x /= 16;
            i ++;
        }
        if (sign == 1){
            j = i;
            *(p + i) = '\0';
        }
        else if (sign == -1){
            *(p + i) = '-';
            *(p + i + 1) = '\0';
            j = i + 1;
        }
        for (i = j - 1; i >= j/2; i --) {
            temp = *(p + i);
            *(p + i) = *(p + j - 1 - i);
            *(p + j - 1 -i) = temp;
        }
    }
}
