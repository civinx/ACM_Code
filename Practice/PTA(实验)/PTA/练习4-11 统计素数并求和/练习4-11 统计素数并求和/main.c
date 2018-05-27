//
//  main.c
//  练习4-11 统计素数并求和
//
//  Created by czf on 15/9/16.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int isPrime(int x);
int main() {
    int m,n;
    int sum = 0;
    int cnt = 0;
    int i;
    
    scanf("%d%d",&m,&n);
    for (i = m; i <= n; i++) {
        if (isPrime(i)) {
            cnt ++ ;
            sum += i;
        }
    }
    printf("%d %d",cnt,sum);
    return 0;
}
int isPrime(int x){
    int i;
    int ret = 1;
    for (i = 2; i < x; i ++) {
        if (x % i == 0) {
            ret = 0;
            break;
        }
    }
    if (x == 1) {
        ret = 0;
    }
    return ret;
}