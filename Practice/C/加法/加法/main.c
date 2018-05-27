//
//  main.c
//  加法
//
//  Created by czf on 15/7/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a = 0;
    int b = 0;
    
    printf("请输入两个整数");
    
    scanf("%d %d",&a,&b);
    
    printf("%d + %d = %d", a , b , a+b );
    
    return 0;
}
