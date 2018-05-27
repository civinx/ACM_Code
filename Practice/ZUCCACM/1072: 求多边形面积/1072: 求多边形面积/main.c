//
//  main.c
//  1072: 求多边形面积
//
//  Created by czf on 15/10/18.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define maxn 105
double x[maxn],y[maxn];
int main() {
    int m;
    while (scanf("%d",&m) && m) {
        double s = 0;
        for (int i = 0; i < m; i ++) {
            scanf("%lf%lf",&x[i+1],&y[i+1]);
        }
        x[m+1] = x[1], y[m+1] = y[1];
        for (int i = 1; i <= m; i ++) {
            s += x[i]*y[i+1] - x[i+1]*y[i];
        }
        s /= 2;
        printf("%.1f\n",s);
    }
    return 0;
}
