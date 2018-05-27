
//
//  main.c
//  素数和
//
//  Created by czf on 15/8/5.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int m,n;
    int x;
    int i;
    int isPrime;
    int sum = 0;
    
    int cnt = 0;
    
    scanf("%d %d",&m,&n);
    for (x = 2; cnt <= n; x ++) {
        isPrime = 1;
        for (i = 2; i < x; i ++) {
            if (x % i ==0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            cnt ++;
            if (cnt>=m && cnt <=n) {
                sum += x;
            }
        }
    }
    printf("%d",sum);
    return 0;
}
