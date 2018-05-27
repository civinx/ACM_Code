//
//  main.cpp
//  1105: 苹果有多少?
//
//  Created by czf on 15/11/4.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

long long bei(long long x, long long y){
    long long t;
    long long a = x, b = y;
    while (y) {
        t = x % y;
        x = y;
        y = t;
    }
    return a*b/x;
}

long long solve(int x){
    if (x == 1 || x == 2) return 2;
    return bei(x, solve(x-1));
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        long long res;
        int n;
        scanf("%d",&n);
        res = solve(n)-1;
        printf("%lld\n",res);
    }
    return 0;
}
