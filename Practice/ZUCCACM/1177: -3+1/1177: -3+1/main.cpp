//
//  main.cpp
//  1177: -3+1
//
//  Created by czf on 15/11/20.
//  Copyright © 2015年 czf. All rights reserved.
//
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    long long n, a[3];
    while(scanf("%lld",&n) == 1){
        a[1] = a[2] = 0;
        long long cnt = 0, ans = 0;
        while(n--){
            int x;
            scanf("%d",&x);
            a[x%3]++;
            cnt += x/3;
            ans += x/3;
        }
        if (ans > 0) cnt += a[2];
        long long m = min(a[1],ans/2);
        cnt += m; ans -= m;
        if(ans >= 3) cnt += (ans-1)/2;
        printf("%lld\n",cnt);
    }
    return 0;
}