//
//  main.cpp
//  2047 阿牛的EOF牛肉串
//
//  Created by czf on 15/12/22.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
typedef long long ll;
int main(){
    ll e[50], o[50], f[50];
    e[1] = o[1] = f[1] = 1;
    for(int i = 2; i < 50; i ++){
        e[i] = e[i-1]+o[i-1]+f[i-1];
        o[i] = e[i-1]+f[i-1];
        f[i] = e[i-1]+o[i-1]+f[i-1];
    }
    int n;
    while(scanf("%d",&n) == 1){
        printf("%lld\n",e[n]+o[n]+f[n]);
    }
    return 0;
}