//
//  main.c
//  实验8-2-2 找最长的字符串
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main() {
    int n;
    int i;
    char x[80];
    char max[80];
    char temp[80];
    
    scanf("%d",&n);
    
    for (i = 0; i < n; i ++) {
        scanf("%s",x);
        if (i == 0) {
            strcpy(max, x);
        }
        if (strlen(x) > strlen(max)) {
            strcpy(temp, x);
            strcpy(x,max);
            strcpy(max, temp);
        }
    }
    
    printf("The longest is: %s",max);
    
    return 0;
}
