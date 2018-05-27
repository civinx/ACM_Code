//
//  main.c
//  ACM DIYA
//
//  Created by czf on 15/9/15.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include<stdio.h>
int main(){
    int a,b;
    int n;
    int sum;
    int sum1;
    int sum2;
    int i;
    int j;
    scanf("%d",&n);
    for (j = 1; j <= n; j ++) {
        scanf("%d%d",&a,&b);
        sum = 0;
        sum1 = 0;
        sum2 =0;
        for (i = 1; i <= a; i ++) {
            sum1 += i;
        }
        for (i = 1; i <= b; i ++) {
            sum2 += i;
        }
        sum = sum1 * sum2;
        printf("%d\n",sum);
        
    }
    return 0;
}