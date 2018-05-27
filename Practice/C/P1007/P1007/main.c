//
//  main.c
//  P1007
//
//  Created by czf on 15/9/11.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num;
    int n;
    double r;
    double y;
    double x;
    double sum;
    double a[100][100];
    
    scanf("%d",&num);
    for (int i = 0; i < num; i ++) {
        int k = 0;
        int m = 0;
        scanf("%lf %lf",&x,&y);
        a[k][m]={x}{y};
        k ++;
        m ++;
    }
    for (i = 0; i < num; i ++) {
        <#statements#>
    }
    return 0;
}
