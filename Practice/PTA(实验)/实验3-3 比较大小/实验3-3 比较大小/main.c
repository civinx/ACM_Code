//
//  main.c
//  实验3-3 比较大小
//
//  Created by czf on 15/9/21.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a,b,c;
    int temp;
    scanf("%d%d%d",&a,&b,&c);
    
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    
    printf("%d->%d->%d",a,b,c);
    
    return 0;
}
