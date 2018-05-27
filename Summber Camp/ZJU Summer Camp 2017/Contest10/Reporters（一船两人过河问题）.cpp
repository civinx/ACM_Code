#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;

const int maxn = 1000 + 10;

int a[maxn];

int solve(int n) {
    int ret = 0;
    while (n) {
        int cost = 0;
        if (n > 3) {
            cost = a[1] * 2 + a[0] + a[n-1];
            cost = min(cost, a[0] * 2 + a[n-1] + a[n-2]);
            ret += cost;
            n -= 2;
        } else if (n > 2) {
            ret += a[0] + a[1] + a[2];
            n -= 3;
        } else if (n > 1){
            ret += a[1];
            n -= 2;
        } else {
            ret += a[0];
            n --;
        }
    }
    return ret;
}


int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        for (int i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
        }
        sort(a, a+n);
        int res = solve(n);
        printf("%d\n",res);
    }
    return 0;
}