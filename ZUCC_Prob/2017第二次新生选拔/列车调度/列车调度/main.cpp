//
//  main.cpp
//  列车调度
//
//  Created by czf on 2017/2/21.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 1;
const int INF = 0x3f3f3f3f;
int f[maxn], a[maxn];

int solve(int n) {
    int ret = 0;
    memset(f, INF, sizeof(f));
    for (int i = 0; i < n; i ++) {
        int pos = int(lower_bound(f, f+n, a[i]) - f);
        f[pos] = a[i];
        ret = max(ret, pos + 1);
    }
    return ret;
}

int main() {
    int n; scanf("%d",&n);
    for (int i = 0; i < n; i ++) scanf("%d",&a[i]);
    printf("%d\n",solve(n));
    return 0;
}
