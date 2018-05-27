//
//  main.c
//  1002: 斐波那契数列
//
//  Created by czf on 15/9/28.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXN 100010
#define BIG 999999999

int main() {
    int f1[MAXN],f2[MAXN];
    int t;
    int i,j;
    int n;
    int temp;
    
    f1[0] = 0; f1[1] = 1;
    f2[0] = 0; f2[1] = 1;
    
    for (i = 2; i < MAXN; i ++) {
        f1[i] = (f1[i - 1] + f1[i - 2]) % 10;
        f2[i] = f2[i - 1] + f2[i - 2];
        if (f2[i] > BIG) {
            f2[i] /= 10;
            f2[i - 1] /= 10;
        }
    }
    scanf("%d",&t);
    
    for (j = 0; j < t; j ++) {
        scanf("%d",&n);
        if (n < 7) {
            printf("%d\n",f1[n]);
        }
        else{
            temp = f2[n];
            while (temp >= 10) {
                temp /= 10;
            }
            printf("%d %d\n",temp,f1[n]);
        }
    }
    return 0;
}

