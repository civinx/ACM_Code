#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define MS(x, y) memset(x, y, sizeof(x))

typedef long long LL;

const int maxn = 100000 + 100;
//const int maxn = 100;


int mp[maxn];
LL sum[maxn];
int n;

inline int lowbit(int x) {
    return x & (-x);
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        sum[i] += v;
    }
}

LL get(int x) {
    LL ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ret += sum[i];
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        MS(sum, 0);
        for (int i = 1; i <= n; i ++) {
            int x; scanf("%d",&x);
            mp[x] = i;
        }
        LL temp = 0;
        for (int i = n; i > 0; i --) {
            int x = mp[i];
            temp += get(x);
            add(x, 1);
        }
        LL res = temp;
        for (int i = n; i > 0; i --) {
            LL x = (LL)mp[i];
            temp += (x - 1) - (n - x);
            res = min(res, temp);
        }
        printf("%lld\n",res);
    }
    return 0;
}