//
//  main.c
//  实验4-2-9 梅森数
//
//  Created by czf on 15/9/21.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int isprinme(int x);

int main() {
    int n;
    int i;
    int num;
    int sign = 0;
    
    scanf("%d",&n);
    
    for (i = 1; i <= n; i ++) {
        num = pow(2, i) - 1;
        if(isprinme(num)){
            sign = 1;
            printf("%d\n",num);
        }
    }
    if (sign == 0) {
        printf("None");
    }
    return 0;
}

int isprinme(int x){
    int i;
    int ret = 1;
    
    for (i = 2; i < x/2; i++) {
        if (x % i == 0) {
            ret = 0;
        }
    }
    if (x == 1) {
        ret = 0;
    }
    
    return ret;
}