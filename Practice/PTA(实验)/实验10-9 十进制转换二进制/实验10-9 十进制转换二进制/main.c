//
//  main.c
//  实验10-9 十进制转换二进制
//
//  Created by czf on 15/9/29.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    dectobin(n);
    
    return 0;
}

void dectobin( int n ){
    if (n / 2 > 0) {
        dectobin(n / 2);
    }
    printf("%d",n % 2);
}
