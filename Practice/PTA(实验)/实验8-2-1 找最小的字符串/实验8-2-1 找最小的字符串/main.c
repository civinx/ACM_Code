//
//  main.c
//  实验8-2-1 找最小的字符串
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main() {
    int n;
    int i;
    char min[80];
    char x[80];
    char temp[80];
    scanf("%d",&n);
    
    for (i = 0; i < n; i ++) {
        scanf("%s",x);
        if (i == 0) {
            strcpy(min, x);
        }
        if (strcmp(min, x) > 0) {
            strcpy(temp, x);
            strcpy(x, min);
            strcpy(min, temp);
        }
    }
    
    printf("Min is: %s",min);
    
    return 0;
}
