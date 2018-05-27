//
//  main.cpp
//  2086 A1 = ?
//
//  Created by czf on 15/12/16.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    double n;
    while(scanf("%lf",&n) == 1){
        double x, y; scanf("%lf%lf",&x,&y);
        double res = n/(n+1)*x + 1/(n+1)*y;
        for(int i = 1; i <= n; i ++){
            double c; scanf("%lf",&c);
            res -= (2*n-2*(i-1))/(n+1)*c;
        }
        printf("%.2f\n",res);
    }
    return 0;
}