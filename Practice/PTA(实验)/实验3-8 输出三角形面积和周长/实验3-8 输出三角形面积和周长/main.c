//
//  main.c
//  实验3-8 输出三角形面积和周长
//
//  Created by czf on 15/9/21.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c;
    double s;
    double area;
    int temp;
    
    scanf("%lf%lf%lf",&a,&b,&c);
    
    if (a > b) {
        temp = a , a = b , b = temp;
    }
    
    if (a > c) {
        temp = a , a = c , c = temp;
    }
    
    if (b > c) {
        temp = b , b = c , c = temp;
    }
    
    if (a + b > c) {
        s = ( a + b +c ) / 2;
        area = sqrt(s * (s - a)*(s - b)*(s - c));
        printf("area = %.2f; perimeter = %.2f",area,s * 2);
    }
    else{
        printf("These sides do not correspond to a valid triangle");
    }
    return 0;
}
