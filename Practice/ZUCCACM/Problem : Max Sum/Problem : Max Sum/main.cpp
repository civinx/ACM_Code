//
//  main.cpp
//  Problem : Max Sum
//
//  Created by czf on 16/5/9.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>

int main() {
    int t, kase = 0; scanf("%d",&t);
    while (t--) {
        int sum = 0, star = 1, end = 1, res = 0;
        int ans = 1;
        int n; scanf("%d",&n);
        bool flag = 0;
        int maxx = -10000, maxi = 1;
        for (int i = 1; i <= n; i ++) {
            int x; scanf("%d",&x);
            if (x > 0) flag = 1;
            if (x > maxx) maxx = x, maxi = i;
            sum += x;
            if (sum > res) { star = ans; end = i; res = sum; }
            if (sum < 0) { sum = 0; ans = i+1;}
        }
        printf("Case %d:\n",++kase);
        if (!flag) printf("%d %d %d\n",maxx, maxi, maxi);
        else printf("%d %d %d\n",res, star, end);
        if (t) printf("\n");
    }
    return 0;
}