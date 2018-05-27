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
#include <cassert>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))
#define INIT int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1
#define FILER freopen("1010.in", "r", stdin)
#define FILEW freopen("test.out", "w", stdout)
using namespace std;
typedef long long LL;

struct Seg {
    LL l, r;
    bool operator < (const Seg & rhs) const {
        if (r == rhs.r) return l < rhs.l;
        return r < rhs.r;
    }
};

bool cmp(const Seg & lhs, const Seg & rhs) {
    if (lhs.l == rhs.l) return lhs.r < rhs.r;
    return lhs.l < rhs.l;
}

const int maxn = 100000 + 100;

Seg a[maxn];
multiset<Seg> s;
multiset<Seg>::iterator it;

int main() {
//    FILER;
//    FILEW;
    int T; scanf("%d",&T);
    while (T--) {
        s.clear();
        int n; scanf("%d",&n);
        for (int i = 0; i < n; i ++) {
            scanf("%lld%lld",&a[i].l,&a[i].r);
        }
        sort(a, a+n, cmp);
        for (int i = 0; i < n; i ++) {
            if (s.empty() || s.begin()->r > a[i].l) {
                s.insert(a[i]);
            } else {
                Seg temp = a[i]; temp.r = temp.l;
                it = s.lower_bound(temp);
                if (it->r != a[i].l) {
                    assert(it != s.begin());
                    it --;
                }
                assert(it->l <= a[i].r);
                temp.l = it->l;
                temp.r = a[i].r;
                s.erase(it);
                s.insert(temp);
            }
        }
        LL res = 0;
        for (it = s.begin(); it != s.end(); it ++) {
            res += (it->r - it->l);
        }
        printf("%d %lld\n",(int)s.size(), res);
    }
    return 0;
}
