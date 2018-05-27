//
//  main.c
//  1007: 简单任务
//
//  Created by czf on 15/9/28.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    char a[100] = {0};
    char x;
    int i;
    int cnt = 0;
    
    while ((scanf("%c",&x)) != EOF) {
        if ((x < 'a' || x > 'z') && (x < 'A' || x > 'Z')) {
            if (cnt > 2) {
                printf("%d",cnt - 2);
                }
            for (i = 0; a[i] != '\0'; i ++) {
            }
            if (cnt > 1) {
                printf("%c",a[i - 1]);
            }
            for (i = 0; a[i] != '\0'; i ++) {
                a[i] = '\0';
            }
            cnt = 0;
            printf("%c",x);
        }
        else{
            if (cnt == 0) {
                printf("%c",x);
            }
            for (i = 0; i != '\0'; i ++) {
            }
            a[i] = x;
            a[i + 1] = '\0';
            cnt ++;
        }
    }
    return 0;
}
