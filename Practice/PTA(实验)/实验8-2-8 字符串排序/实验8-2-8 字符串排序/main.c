//
//  main.c
//  实验8-2-8 字符串排序
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define number 5

int main() {
    int i;
    int j;
    char a[number][80];
    char temp[80];
    
    for (i = 0; i < number; i ++) {
        scanf("%s",a[i]);
    }
    
    for (i = 0; i < number - 1; i ++) {
        for (j = 0; j < number - 1 - i; j ++) {
            if (strcmp(a[j], a[j + 1]) > 0) {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }
    
    printf("After sorted:\n");
    
    for (i = 0; i < number; i ++) {
        printf("%s\n",a[i]);
    }
    return 0;
}
