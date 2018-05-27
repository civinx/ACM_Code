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

const int maxn = 2500 + 10;
//const int maxn = 20;

char s1[maxn], s2[maxn];
bool dp[maxn][maxn];

int main() {
//        freopen("data.in", "r", stdin);
//        freopen("test.out", "w", stdout);
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%s%s",s1+1,s2+1);
        s1[0] = 'x';
        s2[0] = 'x';
        MS(dp, 0);
        dp[0][0] = 1;
        int n = (int)strlen(s1);
        int m = (int)strlen(s2);
        n --;
        m --;
        for (int j = 0; j <= m; j ++) {
            if (s2[j] == '.' && j) {
                for (int i = 1; i <= n; i ++) {
                    if (dp[i-1][j-1]) {
                        dp[i][j] = 1;
                    }
                }
            } else if (s2[j] == '*') {
                for (int i = 0; i <= n; i ++) {
                    if (dp[i][j-1] == 1) { // 不添加
                        dp[i][j] = 1;
                    }
                    if (dp[i][j-2] == 1) { // 删除
                        dp[i][j] = 1;
                    }
                    if (i && dp[i-1][j-1] && s1[i-1] == s1[i]) { // 添加1个
                        dp[i][j] = 1;
                    }
                    if (i && dp[i-1][j] && s1[i-1] == s1[i]) { // 添加多个
                        dp[i][j] = 1;
                    }
                }
            } else if (j) {
                for (int i = 1; i <= n; i ++) {
                    if (dp[i-1][j-1] && s1[i] == s2[j]) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        if (dp[n][m]) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
