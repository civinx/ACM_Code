//
//  main.cpp
//  Problem : Co-prime （容斥原理）
//
//  Created by czf on 16/4/3.
//  Copyright © 2016年 czf. All rights reserved.
//
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 100;
ll a[maxn], cnt;

void solve_1(ll n) {
    cnt = 0;
    for(int i = 2; i*i <= n; i ++) {
        if (n % i == 0) a[cnt++] = i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) a[cnt++] = n;
}

ll solve_2(ll m) {
    ll ans[100] = {-1};
    ll last = 1;
    for(int i = 0; i < cnt; i ++) {
        ll k = last;
        for(int j = 0; j < k; j ++) {
            ans[last++] = a[i] * ans[j] * -1;
        }
    }
    ll ret = 0;
    for(int i = 1; i < last; i ++) {
        ret += m / ans[i];
    }
    return ret;
}

int main() {
    int t; scanf("%d",&t);
    int kase = 0;
    while(t--) {
        ll A, B, N; scanf("%lld%lld%lld",&A,&B,&N);
        solve_1(N);
        ll r = B - solve_2(B), l = A - 1 - solve_2(A-1);
        printf("Case #%d: %lld\n",++kase,r-l);
    }
    return 0;
}