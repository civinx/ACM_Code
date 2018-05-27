//
//  main.c
//  习题4-1 求奇数和
//
//  Created by czf on 15/9/16.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int x;
    int sum = 0;
    
    scanf("%d",&x);
    while (x > 0) {
        if (x % 2 != 0) {
            sum += x;
        }
        scanf("%d",&x);
    }
    printf("%d",sum);
    return 0;
}
