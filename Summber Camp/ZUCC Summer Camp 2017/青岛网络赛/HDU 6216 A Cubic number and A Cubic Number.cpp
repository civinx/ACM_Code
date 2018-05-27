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

const LL maxn = 1e12;

vector<LL> v;

int main() {
    for (LL i = 1;; i ++) {
        LL x = 3 * i * i + 3 * i + 1;
        if (x > maxn) break;
        v.push_back(x);
    }
    int T; scanf("%d",&T);
    while (T--) {
        LL x; scanf("%lld",&x);
        LL y = * lower_bound(v.begin(), v.end(), x);
        if (x == y) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
