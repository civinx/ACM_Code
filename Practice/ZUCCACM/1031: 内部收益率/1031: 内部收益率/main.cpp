//
//  main.cpp
//  1031: 内部收益率
//
//  Created by czf on 15/12/16.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
double c[15];
int main(){
    int n;
    while(scanf("%d",&n) && n){
        double l = -1, r = 1e6, m, sum;
        for(int i = 0; i <= n; i ++) scanf("%lf",&c[i]);
        c[0] *= -1;
        for(int i = 0; i < 100; i ++){
            m = (l+r)/2, sum = 0;
            double item = 1;
            for(int i = 1; i <= n; i ++){
                sum += item*(1/(m+1))*c[i];
                item *= 1/(m+1);
            }
            if (sum > c[0]) l = m;
            else r = m;
        }
        printf("%.2f\n",m);
    }
    return 0;
}