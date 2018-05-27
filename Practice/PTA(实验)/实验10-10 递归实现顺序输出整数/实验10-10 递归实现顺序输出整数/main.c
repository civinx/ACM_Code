//
//  main.c
//  实验10-10 递归实现顺序输出整数
//
//  Created by czf on 15/9/29.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

void printdigits( int n );

int main()
{
    int n;
				
    scanf("%d", &n);
    printdigits(n);
    
    return 0;
}

void printdigits( int n ){
    if (n / 10 > 0) {
        printdigits(n / 10);
    }
    printf("%d\n",n % 10);
}
