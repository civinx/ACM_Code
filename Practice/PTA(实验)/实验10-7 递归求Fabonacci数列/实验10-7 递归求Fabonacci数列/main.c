//
//  main.c
//  实验10-7 递归求Fabonacci数列
//
//  Created by czf on 15/9/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int f( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    printf("%d\n", f(n));
    
    return 0;
}

int f( int n ){
    if (n == 1 || n == 2) {
        return 1;
    }
    else if (n > 2){
        return f(n - 1) + f(n - 2);
    }
    else{
        return 0;
    }
}