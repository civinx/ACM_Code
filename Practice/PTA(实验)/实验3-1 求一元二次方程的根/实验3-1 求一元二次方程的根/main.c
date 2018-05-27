//
//  main.c
//  实验3-1 求一元二次方程的根
//
//  Created by czf on 15/9/25.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c;
    double delta;
    double x1,x2;
    double xugen1,shibu;
    
    scanf("%lf%lf%lf",&a,&b,&c);
    
    delta = pow(b, 2) - 4 * a * c;
    
    if (delta > 0) {
        if (a == 0 && c != 0) {
            x1 = (c * -1 / b);
            printf("%.2lf",x1);
        }
        else if(a == 0 && c == 0){
            printf("0.00");
        }
        else{
            x1 = (b * -1 + sqrt(delta)) / (a * 2);
            x2 = (b * -1 - sqrt(delta)) / (a * 2);
            printf("%.2lf\n%.2lf",x1,x2);
        }
    }
    else if (delta == 0 && a != 0){
        x1 = (b * -1) / (a * 2);
        printf("%.2lf",x1);
    }
    else if(delta < 0){
        shibu = b * -1 / (a * 2);
        xugen1 = sqrt(delta * -1) / (a * 2);
        if (shibu == 0) {
            printf("0.00+%.2lfi\n0.00-%.2lfi",xugen1,xugen1);
        }
        else{
            printf("%.2lf+%.2lfi\n",shibu,xugen1);
            printf("%.2lf-%.2lfi",shibu,xugen1);
        }
    }
    else if (a == 0 && b == 0 && c != 0){
        printf("Not An Equation");
    }
    else if (a == 0 && b == 0 && c == 0){
        printf("Zero Equation");
    }
    return 0;
}
