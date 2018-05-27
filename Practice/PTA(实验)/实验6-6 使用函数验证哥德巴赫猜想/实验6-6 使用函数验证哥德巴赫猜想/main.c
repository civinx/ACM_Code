//
//  main.c
//  实验6-6 使用函数验证哥德巴赫猜想
//
//  Created by czf on 15/9/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;
    
    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }
    
    return 0;
}

int prime( int p ){
    int i;
    int ret = 1;
    
    if (p % 2 == 0 && p != 2) {
        ret = 0;
    }
    
    for (i = 2; i < p / 2; i ++) {
        if (p % i == 0) {
            ret = 0;
            break;
        }
    }
    if (p == 1) {
        ret = 0;
    }
    return ret;
}

void Goldbach( int n ){
    int i;
    int flag = 0;
    for (i = 2; i <= n / 2; i ++) {
        if (prime(i)==1 && prime(n - i)==1) {
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("%d=%d+%d",n,i,n - i);
    }
}
