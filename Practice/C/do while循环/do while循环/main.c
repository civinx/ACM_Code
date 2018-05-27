//
//  main.c
//  do while循环
//
//  Created by czf on 15/8/2.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n = 0;
    int x;
    scanf("%d",&x);
    
    do{
        n++;
        x/=10;
    }while (x>0);
    printf("%d",n);
    
    return 0;
}
