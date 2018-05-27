//
//  main.c
//  实验4-1-7 特殊a串数列求和
//
//  Created by czf on 15/9/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int add(int x,int i);
int main() {
    int x;
    int n;
    int i;
    int sum = 0;
    
    scanf("%d%d",&x,&n);
    for (i = 1; i <= n; i ++) {
        sum += add(x, i);
    }
    
    printf("s = %d",sum);
    return 0;
}
int add(int x,int i){
    int ret = 0;
    int j;
    int mask = 1;
    
    for (j = 1; j <= i; j ++) {
        ret += x * mask;
        mask *= 10;
    }
    return ret;
}