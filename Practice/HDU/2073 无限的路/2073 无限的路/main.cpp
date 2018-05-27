//
//  main.cpp
//  2073 无限的路
//
//  Created by czf on 15/12/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>
double solve(int x, int y){
    double k = sqrt(2), res = 0;
    for(int i = 1; i < x+y; i ++) res += k*i;
    for(int i = 0; i < x+y; i ++){
        if (i == 0) res += 1;
        else res += sqrt((i*i + (i+1)*(i+1)));
    }
    res += x*k;
    return res;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%.3f\n",fabs(solve(x1,y1)-solve(x2,y2)));
    }
    return 0;
}