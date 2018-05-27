//
//  main.c
//  奇偶个数
//
//  Created by czf on 15/8/3.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a;
    double b;
    int c=0;
    int d=0;
    int x;
    
    while (x != -1){
        scanf("%d",&x);
        
        if(x != -1){
            a = x/2;
            b = x/2.0;
            
            if (a == b) {
            d ++;
            }else
            c ++;
        }
    }
    printf("%d %d",c,d);
    return 0;
    
}
