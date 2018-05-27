//
//  main.c
//  实验10-6 递归计算Ackermenn函数
//
//  Created by czf on 15/9/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int Ack( int m, int n );

int main()
{
    int m, n;
    
    scanf("%d %d", &m, &n);
    printf("%d\n", Ack(m, n));
    
    return 0;
}

int Ack( int m, int n ){
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0 && m > 0){
        return Ack(m - 1, 1);
    }
    else if (m >0 && n>0){
        return Ack(m - 1, Ack(m, n - 1));
    }
    else{
        return 0;
    }
}
