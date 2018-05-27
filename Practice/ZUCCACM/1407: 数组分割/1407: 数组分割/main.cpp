//
//  main.cpp
//  1407: 数组分割
//
//  Created by czf on 15/11/9.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
int a[maxn];
int ans[maxn];
int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n; i ++){
            scanf("%d",&a[i]);
            if (i != 0)
                ans[i] = ans[i-1] + a[i];
            else
                ans[i] = a[i];
        }
        int sum = ans[n-1];
        for (int i = 0; i < n; i ++) {
            ans[i] = abs(2*ans[i] - sum);
        }
        sort(ans,ans+n);
        printf("%d\n",ans[0]);
    }
    return 0;
}
