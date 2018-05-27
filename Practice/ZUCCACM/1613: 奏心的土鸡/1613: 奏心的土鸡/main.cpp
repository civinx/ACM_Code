//
//  main.cpp
//  1613: 奏心的土鸡
//
//  Created by czf on 15/12/21.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
typedef long long ll;
const int maxn = 1000000007;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        ll n, m, s, k;
        scanf("%lld%lld%lld%lld",&n,&m,&s,&k);
        n %= maxn; m %= maxn; s %= maxn; k %= maxn;
        ll f2 = (s+1-m), f1 = m, f;
        if (f2 < 0) f2 += maxn;
        for (ll i = n-1; i!=k-1; i--) {
            f = (f2 - f1);
            if (f < 0) f += maxn;
            f2 = f1;
            f1 = f;
        }
        printf("%lld\n",f%maxn);
    }
    return 0;
}