//
//  main.c
//  实验4-2-6 输出三角形字符阵列
//
//  Created by czf on 15/10/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char x;
    int i,j;
    int n;
    
    x = 'A';
    
    scanf("%d",&n);
    
    for (i = n; i > 0; i --) {
        for (j = 0; j < i; j ++) {
            printf("%c ",x);
            x += 1;
        }
        printf("\n");
    }
    
    return 0;
}
