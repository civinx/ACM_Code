//
//  main.c
//  实验10-1 圆形体体积计算器
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define PI 3.141592654

double ball(double radius);
double cylinder(double radius,double h);
double cone(double radius,double h);

int main() {
    int x;
    double r,h;
    double v;
    
    printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:\n");
    scanf("%d",&x);
    while (x == 1 || x == 2 || x == 3) {
        if (x == 1) {
            printf("Please enter the radius:\n");
            scanf("%lf",&r);
            v = ball(r);
            printf("%.2lf\n",v);
        }
        if (x == 2) {
            printf("Please enter the radius and the height:\n");
            scanf("%lf%lf",&r,&h);
            v = cylinder(r, h);
            printf("%.2lf\n",v);
        }
        if (x == 3) {
            printf("Please enter the radius and the height:\n");
            scanf("%lf%lf",&r,&h);
            v = cone(r, h);
            printf("%.2lf\n",v);
        }
        printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:\n");
        scanf("%d",&x);
    }
    return 0;
}

double ball(double radius){
    double v;
    v = (4.0/3) * PI * pow(radius, 3);
    return v;
}
double cylinder(double radius,double h){
    double v;
    v = PI * radius * radius * h;
    return v;
}
double cone(double radius,double h){
    double v;
    v = (1.0/3) * PI * radius * radius * h;
    return v;
}