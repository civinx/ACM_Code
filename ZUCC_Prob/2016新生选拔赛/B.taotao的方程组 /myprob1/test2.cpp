#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 32;
int a[maxn], b[maxn];

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int x, y; scanf("%d%d",&x,&y);
        y >>= 1;
        for (int i = 0; i < maxn; i ++) {
            int l = (x>>i) & 1;
            int r = (y>>i) & 1;
            if (l == 1) {
                a[i] = 1;
                b[i] = 0;
            } else {
                if (r == 1) a[i] = b[i] = 1;
                else a[i] = b[i] = 0;
            }
        }
        int l = 0, r = 0;
        for (int i = maxn-1; i >= 0; i --) {
            l = l * 2 + a[i];
            r = r * 2 + b[i];
        }
        printf("Case #%d: %d\n",++kase,l+r);
    }
    return 0;
}
