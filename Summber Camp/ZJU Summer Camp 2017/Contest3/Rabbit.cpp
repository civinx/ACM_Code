#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long LL;

const int maxn = 1111;

int num[100];
LL dp[100][2];

LL dfs(int pos, int pre, int limit) {
    if (pos == -1) {
        return 1;
    }
    if (!limit && dp[pos][pre] != -1) {
        return dp[pos][pre];
    }
    int end = (limit ? num[pos] : 1);
    LL ret = 0;
    ret += dfs(pos-1, 0, limit && (end == 0));
    if (pre != 1 && end == 1) {
        ret += dfs(pos - 1, 1, limit && (end == 1));
    }
    //    for (int i = 0; i <= end; i ++) {
    //        int g = limit && (i == end);
    //        if (pre == 0) {
    //            ret += dfs(pos-1, 1, g);
    //            ret += dfs(pos-1, 0, g);
    //        } else {
    //            ret += dfs(pos-1, 0, g);
    //        }
    //    }
    if (!limit) {
        dp[pos][pre] = ret;
    }
    return ret;
}

LL solve(LL n) {
    int pos = 0;
    while (n) {
        num[pos++] = n % 2;
        n /= 2;
    }
    return dfs(pos-1, 0, 1);
}

int main() {
    LL n;
    while (scanf("%lld",&n) && (n >= 0)) {
        memset(dp, -1, sizeof(dp));
        printf("%lld\n",solve(n) - 1);
    }
}
