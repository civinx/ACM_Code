//
//  main.c
//  实验7-3-5 输出大写英文字母
//
//  Created by czf on 15/9/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(){
    char str[80];
    int new[27];
    int i;
    int sign = -1;
    
//    for (i = 0; i < 27; i ++) {
//        new[i] = 0;
//    }
    memset(new, 0, sizeof(new));
    i = 0;
    while ((str[i] = getchar()) != '\n') {
        i ++;
    }
    str[i] = '\0';
    
    for (i = 0; str[i] != '\0'; i ++) {
        if (str[i] >= 'A' && str[i] <= 'Z' ) {
            if (new[str[i]-'A'] == 0) {
                printf("%c",str[i]);
                new[str[i]-'A'] ++;
            }
            sign = 1;
        }
    }
    
    if (sign == -1) {
        printf("Not Found");
    }
    return 0;
}
