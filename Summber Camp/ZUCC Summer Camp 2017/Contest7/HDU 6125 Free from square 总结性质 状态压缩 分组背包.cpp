#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
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

const int p[8] = {2, 3, 5, 7, 11, 13, 17, 19};
const int maxn = 500 + 10;
const LL MOD = 1e9 +7;

vector<int> v[maxn];
int state[maxn], grp[maxn];
LL dp[maxn][maxn];

void init() {
    for (int i = 0; i < maxn; i ++) {
        v[i].clear();
        grp[i] = i;
        state[i] = 0;
    }
    MS(dp, 0); dp[0][0] = 1;
}

LL solve(int n, int k) {
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 8; j ++) {
            int x = p[j];
            if (i % (x * x) == 0) {
                state[i] = -1;
            } else if (i % x == 0) {
                grp[i] /= x;
                state[i] |= (1 << j);
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        if (state[i] == -1) continue;
        if (grp[i] == 1) {
            v[i].push_back(i);
        } else {
            v[grp[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i ++ ) {
        if (state[i] == -1 || v[i].size() == 0) continue;
        for (int j = k; j >= 1; j --) {
            for (int s = 0; s < (1 << 8); s ++) {
                for (int x : v[i]) {
                    int temp = state[x];
                    if (temp & s) continue;
                    dp[j][temp|s] = (dp[j][temp|s] + dp[j-1][s]) % MOD;
                }
            }
        }
    }
    LL ret = 0;
    
    for (int i = 1; i <= k; i ++) {
        for (int s = 0; s < (1 << 8); s ++) {
            ret = (ret + dp[i][s]) % MOD;
        }
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        init();
        int n, k; scanf("%d%d",&n,&k);
        printf("%lld\n",solve(n, k));
    }
    return 0;
}
