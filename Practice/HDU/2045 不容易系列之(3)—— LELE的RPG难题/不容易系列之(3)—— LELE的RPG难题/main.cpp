//
//  main.cpp
//  不容易系列之(3)—— LELE的RPG难题
//
//  Created by czf on 15/12/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long r[60], p[60], g[60];
    r[1] = 1; p[1] = 0; g[1] = 0;
    for (int i = 2; i < 60; i ++){
        r[i] = p[i-1] + g[i-1];
        p[i] = r[i-1] + g[i-1];
        g[i] = r[i-1] + p[i-1];
    }
    int n;
    while (scanf("%d",&n) == 1){
        long long res = pow(2,n-1)*3;
        if (n > 1) res -= r[n]*3;
        printf("%lld\n",res);
    }
    return 0;
}