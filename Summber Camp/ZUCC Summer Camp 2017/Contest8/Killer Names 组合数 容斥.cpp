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
const LL MOD = 1e9 + 7;

const int maxn = 2000 + 100;
//const int maxn = 100;

int c[maxn][maxn];
int pw[maxn][maxn];
int fact[maxn];
int s[maxn][maxn];
int n, m;

int mul(int x, int y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

void init(LL n) {
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= n; i ++) c[i][0] = 1;
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
        }
    }
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; i ++) {
        fact[i] = mul(fact[i-1], i);
    }
    for (int i = 1; i <= n; i ++) pw[i][1] = i;
    for (int i = 1; i <= n; i ++) {
        for (int j = 2; j <= n; j ++) {
            pw[i][j] = mul(pw[i][j-1], i);
        }
    }
}


void init2()
{
    int i,n;
    //    LL ans;
    s[0][0]=1;
    for(n=1;n<=2000;n++)
    {
        s[n][0]=0;
        s[n][n]=s[n][1]=1;
        for(i=1;i<=n;i++)
        {
            //            s[n][i]= s[n-1][i-1] + i * s[n-1][i];
            s[n][i] = (s[n-1][i-1] + mul(i, s[n-1][i])) % MOD;
        }
    }
}

LL solve(LL n, LL k) {
    if (k > n) return 0;
    if (k == 1) return 1;
    return c[n-1][k-1];
}

int main() {
    init(2000);
    init2();
    int T; scanf("%d",&T);
    while (T--) {
        LL n, m; scanf("%lld%lld",&n,&m);
        int res = 0;
        for (int i = 1; i <= m-1; i ++) {
            int temp = mul(fact[i], c[m][i]);
            temp = mul(temp, pw[m-i][n]);
            temp = mul(temp, s[n][i]);
            res = (res + temp) % MOD;
        }
        printf("%d\n",res);
    }
    return 0;
}