//
//  main.cpp
//  RPG的错排
//
//  Created by czf on 15/12/19.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
typedef long long ll;
ll c(int n, int k){
    ll ret = 1;
    if (k == 0) return 1;
    for(int i = 1; i <= k; i ++){
        ret *= (n-i+1);
        ret /= i;
    }
    return ret;
}
int main(){
    ll a[30];
    a[1] = 0; a[2] = 1;
    for(int i = 3; i < 15; i ++){
        a[i] = (i-1)*(a[i-1]+a[i-2]);
    }
    int n;
    while(scanf("%d",&n) && n){
        ll sum = 1;
        for(int i = 1; i <= n/2; i ++){
            sum += c(n,i)*a[i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
