//
//  main.c
//  输出0—100的素数
//
//  Created by czf on 15/8/6.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    
    
    for (x = 2; x < 100; x++)
    {
        int i;
        int isPrime = 1;
        for (i = 2; i < x; i ++) {
            if (x % i ==0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1) {
            printf("%d ",x);
        }
    }
    return 0;
}
