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

const LL MOD = 1000000007;

const int maxn = 2222;
//const int maxn = 10;

LL f[maxn][maxn]; int n, m;

LL dfs(int x, int pos) {
    if (pos == m-1) {
        return 1;
    }
    LL ret = 0;
    for (int i = x; i <= n; i += x) {
        if (f[i][pos+1] != -1) {
            ret = (f[i][pos+1] + ret) % MOD;
        } else {
            ret = (dfs(i, pos+1) + ret) % MOD;
        }
    }
    return f[x][pos] = ret;
}
int main() {
    
    while (scanf("%d%d",&n,&m) ==2) {
        MS(f, -1);
        LL res = 0;
        for (int i = 1; i <= n; i ++) {
            res = (res + dfs(i, 0)) % MOD;
        }
        printf("%lld\n",res);
    }
    return 0;
}
