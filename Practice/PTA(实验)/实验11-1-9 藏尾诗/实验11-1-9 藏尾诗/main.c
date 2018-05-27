//
//  main.c
//  实验11-1-9 藏尾诗
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char a[4][19];
    char out[9];
    int i,j;
    
    for (i = 0; i < 4; i ++) {
        scanf("%s",a[i]);
    }
    
    for (i = 0; i < 4; i ++) {
        for (j = 0; a[i][j] != '\0'; j ++) {
        }
        out[2 * i] = a[i][j-2];
        out[2 * i + 1] = a[i][j - 1];
    }
    
    out[2 * i] = '\0';
    
    puts(out);
    
    return 0;
}
