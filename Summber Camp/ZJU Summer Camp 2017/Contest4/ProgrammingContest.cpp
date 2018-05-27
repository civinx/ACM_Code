#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long LL;

const int maxn = 200000 + 100;

int f[maxn];
int a[maxn];
int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        int sum = 0;
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        int V = sum / 2;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i ++) {
            for (int j = V; j >= a[i]; j --) {
                f[j] = max(f[j], f[j - a[i]] + a[i]);
            }
        }
        int mx = f[V];
        printf("%d %d\n",sum - mx, mx);
    }
    return 0;
}
