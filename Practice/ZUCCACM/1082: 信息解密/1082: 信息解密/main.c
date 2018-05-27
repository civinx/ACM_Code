//
//  main.c
//  1082: 信息解密
//
//  Created by czf on 15/10/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char a[40];
    char b[100];
    scanf("%s",a);
    getchar();
    int i = 0;
    while ((b[i] = getchar()) != '\n') {
        i ++;
    }
    b[i] = '\0';
    for (int i = 0; b[i] != '\0'; i ++) {
        if (b[i] >= 'a' && b[i] <= 'z') {
            printf("%c",a[b[i]-'a']);
//            printf("%d",b[i]-'a');
        }
        else if (b[i] >= 'A' && b[i] <= 'Z') {
            char x;
            x = b[i] + 'a' - 'A';
            x = a[x - 'a'];
            x = x + 'A' - 'a';
            printf("%c",x);
        }
        else printf("%c",b[i]);
    }
    return 0;
}
