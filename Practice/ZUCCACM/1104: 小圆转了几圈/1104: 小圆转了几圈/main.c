//
//  main.c
//  1104: 小圆转了几圈
//
//  Created by czf on 15/11/11.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        double n, m;
        scanf("%lf%lf",&n,&m);
        printf("%.2f %.2f\n",(m-n)/n*360,(m+n)/n*360);
    }
    return 0;
}
