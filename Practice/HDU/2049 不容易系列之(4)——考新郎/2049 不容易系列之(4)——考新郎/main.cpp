//
//  main.cpp
//  2049 不容易系列之(4)——考新郎
//
//  Created by czf on 15/12/19.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
typedef long long ll;
const int maxn = 20 + 5;
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
    int t; scanf("%d",&t);
    ll a[maxn]; a[1] = 0; a[2] = 1;
    for(int i = 3; i < maxn; i ++){
        a[i] = (i-1)*(a[i-1]+a[i-2]);
    }
    while(t--){
        int n, m; scanf("%d%d",&n,&m);
        printf("%lld\n",a[m]*c(n,m));
    }
    return 0;
}
