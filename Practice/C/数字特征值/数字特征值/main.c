//
//  main.c
//  数字特征值
//
//  Created by czf on 15/8/3.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,c;
    double b,d;
    int n = 1 ;
    int x;
    int e,f;
    int y = 1;
    int z = 0;
    
    scanf("%d",&x);
    while (x > 0) {
        a = n/2;
        b = n/2.0;
        
        if(n != 1){
            y *= 2;
        }
        
        if (a == b) {
            e = 1;
        }else
            e = 0;
        
        c = x/2;
        d = x/2.0;
        if (c == d) {
            f = 1;
        }else
            f = 0;
        
        if (e == f) {
            z += y;
        }
        x /= 10;
        n ++;
    }
    printf("%d",z);
    
}
