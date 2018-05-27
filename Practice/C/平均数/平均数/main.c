//
//  main.c
//  平均数
//
//  Created by czf on 15/7/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,b;
    
    scanf("%d%d",&a,&b);
    
    double c = (a+b)/2.0;
    
    printf("%d和%d的平均值=%f",a,b,c);
    
    return 0;
    
}
