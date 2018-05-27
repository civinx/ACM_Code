//
//  main.cpp
//  1392: 吕老板的商业街
//
//  Created by czf on 15/11/10.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 100000 + 5;
long long a[maxn] = {0};
int main() {
    int n, m;
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld",&a[i]);
        a[i] += a[i-1];
    }
    scanf("%d",&m);
    while (m--) {
        int i, j;
        scanf("%d%d",&i,&j);
        printf("%lld\n",a[j]-a[i-1]);
    }
    return 0;
}
