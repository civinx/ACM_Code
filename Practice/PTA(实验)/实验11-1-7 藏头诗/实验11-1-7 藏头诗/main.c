//
//  main.c
//  实验11-1-7 藏头诗
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char p[4][20];
    char out[10];
    int i;
    for (i = 0; i < 4; i ++) {
        scanf("%s",p[i]);
    }
    
    for (i = 0; i < 4; i ++) {
        out[2 * i] = p[i][0];
        out[2 * i + 1] = p[i][1];
    }
    out[2 * i] = '\0';
    
    puts(out);
    
    return 0;
}
