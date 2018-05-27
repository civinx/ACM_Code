//
//  main.c
//  变量交换
//
//  Created by czf on 15/7/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a = 1;
    int b = 0;
    int c;
    c=a;
    a=b;
    b=c;
    printf("%d %d",a,b);
    return 0;
    
}
