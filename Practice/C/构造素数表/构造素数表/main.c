//
//  main.c
//  构造素数表
//
//  Created by czf on 15/8/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    const int maxNumber = 25;
    int isPrime[maxNumber];
    int i;
    int x;
    
    for (i = 0; i < maxNumber; i ++) {
        isPrime[i] = 1;
    }
    
    for (x = 2; x < maxNumber; x ++) {
        if (isPrime[x]) {
            for (i = 2; x*i < maxNumber; i ++) {
                isPrime[x*i] = 0;
            }
        }
    }
    
    for (i = 2; i < maxNumber; i++) {
        if (isPrime[i] == 1) {
            printf("%d\t",i);
        }
    }
    return 0;
}
