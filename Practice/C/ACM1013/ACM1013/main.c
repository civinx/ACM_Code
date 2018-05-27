//
//  main.c
//  ACM1013
//
//  Created by czf on 15/9/8.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int x;
    int k;
    
    while (scanf("%d",&x) != EOF) {
        if (x == 1) {
            k = 0;
        }
        else{
            k = x / 2;
        }
        printf("%d\n",k);
    }
    return 0;
}
