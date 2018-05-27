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

double p[maxn];
double dp[maxn][maxn];

int main() {
    int n;
    double A, B;
    while (scanf("%d",&n) && (n >= 0)) {
        scanf("%lf%lf",&A,&B);
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= n; j ++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i ++) {
            scanf("%lf",&p[i]);
        }
        if (n == 0) {
            printf("0.000\n");
            continue;
        }
        dp[1][1] = p[1];
        dp[1][0] = 1 - p[1];
        double res = 0;
        for (int i = 2; i <= n; i ++) {
            // ???0
            dp[i][0] = 1 - p[i];
            for (int j = 1; j < i; j ++) {
                res += dp[i][0] * dp[i-1][j] * (A + B * j) * (A + B * j);
            }
            // ???1
            for (int j = 1; j <= i; j ++) {
                dp[i][j] = dp[i-1][j-1] * p[i];
            }
        }
        for (int i = 1; i <= n; i ++) {
            res += dp[n][i] *  (A + B * i) * (A + B * i);
        }
        printf("%.3f\n",res);
    }
    return 0;
}
