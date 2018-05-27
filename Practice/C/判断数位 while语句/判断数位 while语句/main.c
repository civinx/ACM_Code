//
//  main.c
//  判断数位 while语句
//
//  Created by czf on 15/8/2.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n = 0;
    int x;
    scanf("%d",&x);
    while (x>0) {
        n++;
        x/=10;
    }
    printf("%d",n);
    return 0;
}
