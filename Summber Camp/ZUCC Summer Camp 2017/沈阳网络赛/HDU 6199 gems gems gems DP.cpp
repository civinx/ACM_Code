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
#define pb push_back
#define MS(x, y) memset(x, y, sizeof(x))
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;

const int maxn = 20000 + 10;
const int MOD = 255;

int dp[2][300][256], sum[maxn];

int getSum(int L, int R) {
    return sum[R] - sum[L-1];
}

int main() {
//    FILER;
    int T; scanf("%d",&T);
    while (T--) {
        MS(dp, 0);
        int n; scanf("%d",&n);
        for (int i = 1; i <= n; i ++)  {
            scanf("%d",&sum[i]);
            sum[i] += sum[i-1];
        }
        for (int i = n; i >= 1; i --) {
            for (int j = 1; (1 + j) * j / 2 <= i; j ++) {
                if (i + j - 1 == n) {
                    dp[0][i&MOD][j] = getSum(i, i+j-1);
                    dp[1][i&MOD][j] = -getSum(i, i+j-1);
                    break;
                }
                int g1 = dp[1][i+j&MOD][j] + getSum(i, i+j-1);
                int g2 = dp[1][i+j+1&MOD][j+1] + getSum(i, i+j);
                dp[0][i&MOD][j] = max(g1, g2);
                int g3 = dp[0][i+j&MOD][j] - getSum(i, i+j-1);
                int g4 = dp[0][i+j+1&MOD][j+1] - getSum(i, i+j);
                dp[1][i&MOD][j] = min(g3, g4);
            }
        }
        printf("%d\n",dp[0][1][1]);
    }
    return 0;
}
