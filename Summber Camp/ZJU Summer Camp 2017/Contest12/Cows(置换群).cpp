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
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100;
const int INF = 1e8;

int MIN;

struct Node {
    int val;
    int id;
    bool operator < (const Node & rhs) const {
        return val < rhs.val;
    }
};

Node a[maxn];
bool vis[maxn];

int solve(int n) {
    MS(vis, 0);
    int ret = 0;
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            vis[i] = 1;
            int k = 1, sum = a[i].val, pos = a[i].id, mi = a[i].val;
            while (pos != i) {
                vis[pos] = 1;
                k ++;
                sum += a[pos].val;
                mi = min(mi, a[pos].val);
                pos = a[pos].id;
            }
            ret = ret + sum + min(mi * (k - 2), mi + (k + 1) * MIN);
        }
    }
    return ret;
}

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        MIN = INF;
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&a[i].val);
            a[i].id = i;
            MIN = min(MIN, a[i].val);
        }
        sort(a+1, a+1+n);
        printf("%d\n",solve(n));
    }
    return 0;
}
