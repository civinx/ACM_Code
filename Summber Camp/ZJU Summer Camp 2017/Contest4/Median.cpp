#include <iostream>
#include <stack>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 10000;

int sum[maxn], cnt[maxn * 2];
int a[maxn];
int n;

int solve(int x) {
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    int pos = -1;
    for (int i = 1; i <= n; i ++) {
        int g = 0;
        if (a[i] < x) {
            g = -1;
        } else if (a[i] > x) {
            g = 1;
        } else {
            pos = i;
        }
        sum[i] = sum[i-1] + g;
        if (pos == -1) cnt[sum[i] + n] ++;
    }
    cnt[n] ++;
    int ret = 0;
    for (int i = pos; i <= n; i ++) {
        ret += cnt[sum[i] + n];
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&a[i]);
        }
        for (int i = 1; i <= n; i ++) {
            printf("%d%c",solve(a[i]),i==n?'\n':' ');
        }
    }
    return 0;
}
