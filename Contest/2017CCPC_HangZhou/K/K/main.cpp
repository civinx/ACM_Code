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

const int maxn = 1000 + 10;
const int mx = 1000;
LL pre[maxn][maxn], num[maxn];
LL a[maxn], b[maxn];
LL sum = 0;
int n, m;

void init() {
    MS(pre, 0); MS(num, 0); sum = 0;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld",&a[i]);
        num[a[i]] ++;
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%lld",&b[i]);
    }
    for (int i = 1; i <= n; i ++) {
        pre[a[i]][b[i]%a[i]] ++;
        sum += -b[i] / a[i];
        if (b[i] % a[i]) sum --;
    }
    for (int i = 1; i <= mx; i ++) {
        for (int j = 1; j < mx; j ++) {
            pre[i][j] += pre[i][j-1];
        }
    }
}

void updateSum(int pos, int x, LL * c) {
    LL g = -b[pos] / a[pos];
    if (b[pos] % a[pos]) g --;
    sum -= g;
    c[pos] = x;
    g = -b[pos] / a[pos];
    if (b[pos] % a[pos]) g --;
    sum += g;
}

void modifyA(int pos, int x) {
    for (int i = (int)b[pos]%a[pos]; i < mx; i ++) {
        pre[a[pos]][i] --;
    }
    num[a[pos]] --;
    updateSum(pos, x, a);
    num[a[pos]] ++;
    for (int i = (int)b[pos]%a[pos]; i < mx; i ++) {
        pre[a[pos]][i] ++;
    }
}

void modifyB(int pos, int x) {
    for (int i = (int)b[pos]%a[pos]; i < mx; i ++) {
        pre[a[pos]][i] --;
    }
    updateSum(pos, x, b);
    for (int i = (int)b[pos]%a[pos]; i < mx; i ++) {
        pre[a[pos]][i] ++;
    }
}

LL check(LL t, LL k) {
    LL g = 0;
    for (int i = 1; i <= mx; i ++) {
        g += pre[i][t%i] - pre[i][0] + (t / i) * num[i];
    }
    return sum + g >= k;
}

int main() {
    freopen("data.in", "r", stdin);
    int T; scanf("%d",&T);
    while (T--) {
        init();
        while (m--) {
            int op; scanf("%d",&op);
            if (op == 1) {
                int pos, x; scanf("%d%d",&pos,&x);
                modifyA(pos, x);
            } else if (op == 2) {
                int pos, x; scanf("%d%d",&pos,&x);
                modifyB(pos, x);
            } else {
                LL k; scanf("%lld",&k);
                LL L = 0, R = 1e13;
                while (L < R) {
                    LL mid = (L + R) / 2;
                    if (check(mid, k)) R = mid;
                    else L = mid + 1;
                }
                printf("%lld\n",L);
            }
        }
    }
    return 0;
}


