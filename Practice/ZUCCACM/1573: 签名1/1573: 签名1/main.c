//
//  main.c
//  1573: 签名1
//
//  Created by czf on 15/10/9.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char a[1010];
    char y;
    int i;
    int cnt;
    
    gets(a);
    
    y = ' ';
    cnt = 0;
    
    for (i = 0; a[i] != '\0'; i ++) {
        if (a[i] != ' ' && y == ' ') {
            cnt ++;
        }
        y = a[i];
    }
    
    printf("%d",cnt);
    
    return 0;
}
