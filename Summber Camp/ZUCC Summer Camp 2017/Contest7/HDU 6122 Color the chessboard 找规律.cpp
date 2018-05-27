#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
#define INIT int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;

const int maxn = 1000 + 100;
const LL MOD = 998244353;
LL row[maxn], col[maxn];
char mp[maxn][maxn];

int n, m;

void solveRow() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (row[i] == 3) break;
            char c = mp[i][j];
            if (c == '?') continue;
            if (row[i] == 0) {
                if (c == 'R' && j % 2 == 1) row[i] = 1;
                if (c == 'B' && j % 2 == 0) row[i] = 1;
                if (c == 'R' && j % 2 == 0) row[i] = 2;
                if (c == 'B' && j % 2 == 1) row[i] = 2;
            } else if (row[i] == 1) {
                if (c == 'R' && j % 2 == 0) row[i] = 3;
                if (c == 'B' && j % 2 == 1) row[i] = 3;
            } else if (row[i] == 2) {
                if (c == 'R' && j % 2 == 1) row[i] = 3;
                if (c == 'B' && j % 2 == 0) row[i] = 3;
            }
        }
    }
}

void solveCol() {
    for (int j = 1; j <= m; j ++) {
        for (int i = 1; i <= n; i ++) {
            if (col[j] == 3) break;
            char c = mp[i][j];
            if (c == '?') continue;
            if (col[j] == 0) {
                if (c == 'R' && i % 2 == 1) col[j] = 1;
                if (c == 'B' && i % 2 == 0) col[j] = 1;
                if (c == 'R' && i % 2 == 0) col[j] = 2;
                if (c == 'B' && i % 2 == 1) col[j] = 2;
            } else if (col[j] == 1) {
                if (c == 'R' && i % 2 == 0) col[j] = 3;
                if (c == 'B' && i % 2 == 1) col[j] = 3;
            } else if (col[j] == 2) {
                if (c == 'R' && i % 2 == 1) col[j] = 3;
                if (c == 'B' && i % 2 == 0) col[j] = 3;
            }
        }
    }
}

int sub(int st) {
    for (int i = 1; i <= n; i ++) {
        if (row[i] && row[i] != st) return 0;
        st = 3 - st;
    }
    return 1;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        MS(row, 0);
        MS(col, 0);
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i ++) {
            scanf("%s",mp[i]+1);
        }
        solveCol();
        solveRow();
        LL res = 0, temp = 1;
        for (int i = 1; i <= n; i ++) {
            LL g = 0;
            if (row[i] == 1 || row[i] == 2) g = 1;
            if (row[i] == 0) g = 2;
            temp *= g; temp %= MOD;
            if (!g) break;
        }
        res += temp; res %= MOD;
        temp = 1;
        for (int i = 1; i <= m; i ++) {
            LL g = 0;
            if (col[i] == 1 || col[i] == 2) g = 1;
            if (col[i] == 0) g = 2;
            temp *= g; temp %= MOD;
            if (!g) break;
        }
        res += temp; res %= MOD;
        res -= sub(1);
        res -= sub(2);
        res = (res % MOD + MOD) % MOD;
        printf("%lld\n",res);
    }
    return 0;
}
