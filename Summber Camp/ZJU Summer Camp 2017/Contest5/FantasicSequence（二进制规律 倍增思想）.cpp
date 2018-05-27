#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;
//const int maxn = 100;

int a[maxn], sum[maxn];

int f[maxn][50];

int check(int x) {
    int ret = 0;
    while (x) {
        if (x & 1) ret ++;
        x /= 2;
    }
    return ret & 1;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1] + a[i];
            f[i][0] = 0;
        }
        for (int k = 1; (1 << k) <= n; k ++) {
            for (int i = 1; i + (1 << k) - 1 <= n; i ++) {
                int R = (1 << k) + i - 1;
                int L = (1 << (k-1)) + i;
                f[i][k] = f[i][k-1] + (sum[R] - sum[L-1] - f[L][k-1]);
            }
        }
        int q; scanf("%d",&q);
        while (q--) {
            int x, y, len; scanf("%d%d%d",&x,&y,&len);
            int res = 0;
            while (len) {
                int k = 0;
                while ((1 << k) <= len && y % (1 << k) == 0)
                    k ++;
                k --;
                int g = (1 << k);
                if (check(y)) {
                    res += sum[x + g - 1] - sum[x-1] - f[x][k];
                } else {
                    res += f[x][k];
                }
                len -= g;
                x += g;
                y += g;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
