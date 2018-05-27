//
//  main.c
//  实验9-10 平面向量加法
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
struct xiangliang{
    double x;
    double y;
};

int main() {
    
    struct xiangliang a,b,c;
    
    scanf("%lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y);
    
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    if (c.x > -0.05 && c.x < 0) {
        c.x = 0;
    }
    if (c.y > -0.05 && c.y < 0) {
        c.y = 0;
    }
    printf("(%.1lf, %.1lf)",c.x,c.y);
    
    return 0;
}
