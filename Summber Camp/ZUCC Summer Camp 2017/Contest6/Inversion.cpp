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
#include <ctime>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;

typedef long long LL;

const int maxn = 100000 + 100;

struct P {
    LL val;
    int pos;
    bool operator < (const P & rhs) const {
        return val > rhs.val;
    }
};

P a[maxn];

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        vector<LL> res;
        for (int i = 1; i <= n; i ++) {
            scanf("%lld",&a[i].val);
            a[i].pos = i;
        }
        sort(a+1, a+1+n);
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (a[j].pos % i) {
                    res.push_back(a[j].val);
                    break;
                }
            }
        }
        for (int i = 0; i < res.size(); i ++) {
            printf("%lld%c",res[i],i==res.size()-1?'\n':' ');
        }
    }
    return 0;
}