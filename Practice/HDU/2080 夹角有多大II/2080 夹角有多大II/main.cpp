//
//  main.cpp
//  2080 夹角有多大II
//
//  Created by czf on 15/12/15.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>
const double pi = acos(-1);
int main(){
    int t; scanf("%d",&t);
    while(t--){
        double x1, y1, x2, y2;
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        double x = (x1*x2 + y1*y2) / (sqrt(x1*x1+y1*y1) * sqrt(x2*x2+y2*y2));
        printf("%.2f\n",acos(x)*180/pi);
    }
    return 0;
}