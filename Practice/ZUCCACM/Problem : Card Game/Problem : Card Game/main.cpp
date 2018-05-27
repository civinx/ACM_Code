//
//  main.cpp
//  Problem : Card Game
//
//  Created by czf on 15/10/19.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 500 + 10;
int a[maxn];
int b[maxn];
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n ; i ++) scanf("%d",&a[i]);
        for (int i = 0; i < n ; i ++) scanf("%d",&b[i]);
        sort(a,a+n); sort(b,b+n);
        int sum1 = 0,sum2 = 0;
        for (int i = 0; i < m; i ++) sum1 += a[i];
        for (int i = n-1; i > n-1-m; i--) sum2 += b[i];
        if (sum1 > sum2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
