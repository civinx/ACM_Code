//
//  main.c
//  test1week
//
//  Created by czf on 15/7/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int x;
    int a,b,c;
    
    scanf("%d",&x);
    a =x / 100;
    b =x / 10 % 10;
    c =x % 10;
    
    printf("%d",c*100+b*10+a);
    
    return 0;
}
