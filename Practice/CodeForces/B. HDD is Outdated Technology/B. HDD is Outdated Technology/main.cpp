//
//  main.cpp
//  B. HDD is Outdated Technology
//
//  Created by czf on 15/12/26.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
const int maxn = 200000 + 50;
int num[maxn], a[maxn];
int main(){
    int n; scanf("%d",&n);
    for(int i = 1; i <= n; i ++) scanf("%d",&num[i]);
    for(int i = 1; i <= n; i ++) a[num[i]] = i;
    long long res = 0;
    for(int i = 1; i < n; i ++){
        res += std::abs(a[i]-a[i+1]);
    }
    printf("%lld\n",res);
    return 0;
}
