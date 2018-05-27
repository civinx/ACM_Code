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

const int maxn = 100000 + 100;
int num[2][32];
int a[maxn];

void solve(int x) {
    for (int i = 0; i < 32; i ++) {
        int g = !!((1 << i) & x);
        num[g][i] ++;
    }
}

int AND(int x) {
    int res = 0;
    for (int i = 0; i < 32; i ++) {
        int g = !!((1 << i) & x);
        if (g == 0 && num[0][i] == 1) {
            res |= (1 << i);
        } else {
            res |= (num[0][i] ? 0 : (1 << i));
        }
    }
    return res;
}

int OR(int x) {
    int res = 0;
    for (int i = 0; i < 32; i ++) {
        int g = !!((1 << i) & x);
        if (g == 1 && num[1][i] == 1) {
            res |= 0;
        } else {
            res |= (num[1][i] ? (1 << i) : 0);
        }
    }
    return res;
}

int XOR(int x) {
    int res = 0;
    for (int i = 0; i < 32; i ++) {
        int g = !!((1 << i) & x);
        if (g == 0) {
            res |= (num[1][i] & 1 ? (1 << i) : 0);
        } else {
            res |= (num[1][i] & 1 ? 0 : (1 << i));
        }
    }
    return res;
}

int main() {
    int n, q;
    while (scanf("%d%d",&n,&q) == 2) {
        MS(num, 0);
        for (int i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
            solve(a[i]);
        }
        while (q--) {
            int pos; scanf("%d",&pos); pos --;
            int x = AND(a[pos]), y = OR(a[pos]), z = XOR(a[pos]);
            printf("%d %d %d\n",x,y,z);
        }
    }
    return 0;
}