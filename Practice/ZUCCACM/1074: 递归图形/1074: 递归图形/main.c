//
//  main.c
//  1074: 递归图形
//
//  Created by czf on 15/10/18.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define pai 3.14159
double r(int x,int n);
int main() {
    int t;
    scanf("%d",&t);
    while (t --) {
        double n;
        double sum = 0;
        int k;
        scanf("%lf%d",&n,&k);
        sum = pai * r(k,n) * r(k,n);
        for (int i = k-1; i >= 1; i --) {
            sum += pai * r(i, n) * r(i, n) - r(i+1, n) * r(i+1, n) * 4;
        }
        printf("%.3f\n",sum);
    }
    return 0;
}

double r(int x,int n){
    double ret = n/pow(sqrt(2), x-1)/2;
    return ret;
}
