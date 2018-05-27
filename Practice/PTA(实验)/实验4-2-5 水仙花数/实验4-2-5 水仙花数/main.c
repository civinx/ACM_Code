//
//  main.c
//  实验4-2-5 水仙花数
//
//  Created by czf on 15/10/5.
//  Copyright © 2015年 czf. All rights reserved.
//

#include<stdio.h>
#include<math.h>
int main(void)
{
    int n,i,num,j,b,c;
    double sum;
    int a [10][5];
    
    for (b = 0 ;b <= 9 ;b ++ )
        for (c = 0 ;c < 5 ;c ++ )
            a[b][c] = pow(b,c+3);
    
    scanf("%d",&n);
    
    for(i = pow(10,n-1) ;i < pow(10,n) ;i++ ) {
        num = i;
        sum = 0;
        while (num != 0) {
            j = num % 10;
            num = num/10;
            sum = sum + a[j][n - 3];
        }
        if (sum == i) printf("%d\n",i);
    }
    
    return 0;
}