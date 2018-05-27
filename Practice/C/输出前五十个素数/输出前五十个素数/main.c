//
//  main.c
//  输出前五十个素数
//
//  Created by czf on 15/8/6.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    int cnt = 0;
    
    for (x = 2; cnt < 50; x ++) {
        int i;
        int isPrime = 1;
        for (i = 2; i < x; i ++) {
            if (x % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1) {
            printf("%d ",x);
            cnt ++;
        }
    }
    return 0;
}
