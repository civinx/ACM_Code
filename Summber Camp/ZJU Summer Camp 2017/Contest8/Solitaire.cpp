#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1000000 + 100;
//const int maxn = 100;
int sum[maxn];
int a[maxn];
int cnt[maxn];

int main() {
    int n, m;
    while (scanf("%d%d",&n,&m) && (n || m)) {
        int p = n / m;
        for (int i = 0; i < n; i ++) {
            int x, y; scanf("%d%d",&x,&y);
            a[i] = (y-1) * p + x;
        }
        int res = 0;
        memset(sum, -1, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i ++) {
            int x = a[i];
            if ((x - 1) % p == 0) {
                sum[x] = 0;
            } else {
                if (sum[x-1] == -1) {
                    cnt[(x-1)/p] ++;
                    sum[x] = 0;
                } else {
                    sum[x] = 0;
                }
            }
        }
        int g = 0;
        for (int i = 0; i < m; i ++) {
            g = max(g, cnt[i]);
        }
        res = n * 10 - g * 100;
        printf("%d\n",res);
    }
    return 0;
}