//
//  main.c
//  素数和（函数版）
//
//  Created by czf on 15/8/8.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
int isPrime(x){
    int ret = 1;
    
    for (int i = 2; i < x; i ++) {
        if (x % i ==0) {
            ret = 0;
            break;
        }
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    int m,n;
    int x;
    int sum = 0;
    int cnt = 0;
    
    scanf("%d %d",&m,&n);
    for (x = 2; cnt <= n; x ++) {
        if (isPrime(x)) {
            cnt ++;
            if (cnt>=m && cnt <=n) {
                sum += x;
            }
        }
    }
        printf("%d",sum);
    return 0;
}
