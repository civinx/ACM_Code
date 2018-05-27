//
//  main.c
//  实验8-2-10 IP地址转换
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main() {
    double a,b,c,d;
    int i;
    char ip[33];
    
    gets(ip);
    
    a = b = c = d = 0;
    
    for (i = 0; i < 8; i ++) {
        a += pow(2, 7 - i) * (ip[i] - '0');
    }
    for (i = 8; i < 16; i ++) {
        b += pow(2, 15 - i) * (ip[i] - '0');
    }
    for (i = 16; i < 24; i ++) {
        c += pow(2, 23 - i) * (ip[i] - '0');
    }
    for (i = 24; i < 32; i ++) {
        d += pow(2, 31 - i) * (ip[i] - '0');
    }
    
    printf("%.lf.%.lf.%.lf.%.lf",a,b,c,d);
    
    return 0;
}
