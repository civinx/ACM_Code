#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#define MS(a, x) memset(a, x, sizeof(a))
using namespace std;

typedef long long LL;

const int maxn = 500000 + 100;
//const int maxn = 500;


int ch[maxn*30][2];
int cnt[32][2];
int val[maxn*30];
int sz;
LL sum[maxn*30];

void init () {
    sz = 1;
    MS(ch[0], 0);
    MS(sum, 0);
    MS(val, 0);
    MS(cnt, 0);
}

int newnode() {
    MS(ch[sz], 0);
    val[sz] = 0;
    return sz ++;
}

void insert(int x, int v) {
    int cur = 0;
    for (int i = 30; i >= 0; i --) {
        int bit = ((1 << i) & x) > 0;
        if (!ch[cur][bit]) {
            ch[cur][bit] = newnode();
        }
        cur = ch[cur][bit];
        cnt[i][bit] ++;
        val[cur] += v;
        sum[cur] += v * cnt[i][bit ^ 1];
    }
}

LL query(int x) {
    LL ret = 0;
    int cur = 0, inv;
    for (int i = 30; i >= 0; i --) {
        int bit = ((1 << i) & x) > 0;
        inv = ch[cur][bit ^ 1];
        cur = ch[cur][bit];
        if (inv)
            ret += sum[inv] - (LL)val[inv] * (LL)cnt[i][bit];
//        if (cur == 0) break;
    }
    return ret;
}

int a[maxn];

int main() {
//    freopen("1004.in", "r", stdin);
//    freopen("1004test.out", "w", stdout);
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        init();
        for (int i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
            insert(a[i], 1);
        }
        MS(cnt, 0);
        LL res = 0;
        for (int i = 0; i < n; i ++) {
            insert(a[i], -1);
            res += query(a[i]);
        }
        printf("%lld\n",res);
    }
    return 0;
}
