//
//  main.c
//  实验11-1-1 英文单词排序
//
//  Created by czf on 15/9/29.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char *color[20];
    char str[10];
    char *temp;
    int n;
    int i,j;
    
    scanf("%s",str);
    
    n = 0;
    
    while (str[0] != '#') {
        color[n] = (char *)malloc(sizeof(char)*(strlen(str)+1));
        strcpy(color[n], str );
        n ++;
        scanf("%s",str);
    }
    
    for (i = 0; i < n - 1; i ++) {
        for (j = 0; j < n - i - 1; j ++) {
            if (strlen(color[j]) > strlen(color[j + 1])) {
                temp = color[j];
                color[j] = color[j + 1];
                color[j + 1] = temp;
            }
        }
    }
    
    for (i = 0; i < n; i ++) {
        printf("%s ",color[i]);
    }
    
    return 0;
}
