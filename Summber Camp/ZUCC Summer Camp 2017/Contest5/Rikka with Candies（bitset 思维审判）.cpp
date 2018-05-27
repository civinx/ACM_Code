#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;

typedef long long LL;

const int maxn = 50000 + 10;

bitset<maxn> a, b, sum;
int res[maxn];

void solve(int maxK, int maxA) {
    for (int k = maxK; k >= 0; k --) {
        res[k] = (int)((a >> k) & sum).count();
        if (!b[k]) continue;
        for (int i = 0; i <= maxA; i += k) {
            sum.flip(i);
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        a.reset(); b.reset(); sum.reset();
        int n, m, q; scanf("%d%d%d",&n,&m,&q);
        int maxA = 0;
        for (int i = 0; i < n; i ++) {
            int x; scanf("%d",&x);
            a.set(x);
            maxA = max(maxA, x);
        }
        int maxK = 0;
        for (int i = 0; i < m; i ++) {
            int x; scanf("%d",&x);
            b.set(x);
            maxK = max(maxK, x);
        }
        solve(maxK, maxA);
        for (int i = 0; i < q; i ++) {
            int x; scanf("%d",&x);
            printf("%d\n",res[x] & 1);
        }
    }
    return 0;
}

