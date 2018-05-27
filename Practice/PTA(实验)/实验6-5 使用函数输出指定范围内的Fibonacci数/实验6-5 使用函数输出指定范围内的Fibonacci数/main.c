//
//  main.c
//  实验6-5 使用函数输出指定范围内的Fibonacci数
//
//  Created by czf on 15/9/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );

int main()
{
    int m, n, t;
    
    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);
    
    return 0;
}

int fib( int n ){
    if (n == 1 || n == 2) {
        return 1;
    }
    else{
        return fib(n - 1) + fib(n - 2);
    }
}

void PrintFN( int m, int n ){
    int i;
    int flag;
    
    i = 1;
    flag = 0;
    while (fib(i) <= n) {
        if (fib(i) >= m) {
            if (flag == 0) {
                printf("%d",fib(i));
            }
            else{
                printf(" %d",fib(i));
            }
            flag = 1;
        }
        i ++;
    }
    
    if (flag == 0) {
        printf("No Fibonacci number");
    }
}