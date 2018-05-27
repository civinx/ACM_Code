//
//  main.cpp
//  1086: 多边形重心
//
//  Created by czf on 15/11/21.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>

struct point{
    double x, y;
};
double area(point p1, point p2, point p3){
    return ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y)) / 2;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        point p1, p2, p3;
        double rx = 0, ry = 0, temp, sumarea = 0;
        scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
        for(int i = 2; i < n; i ++){
            scanf("%lf%lf",&p3.x,&p3.y);
            temp = area(p1,p2,p3);
            rx += (p1.x + p2.x + p3.x) * temp;
            ry += (p1.y + p2.y + p3.y) * temp;
            sumarea += temp;
            p2 = p3;
        }
        rx = rx/sumarea/3;
        ry = ry/sumarea/3;
        if (rx == -0) rx = 0;
        if (ry == -0) ry = 0;
        printf("%.2f %.2f\n",rx,ry);
    }
    return 0;
}