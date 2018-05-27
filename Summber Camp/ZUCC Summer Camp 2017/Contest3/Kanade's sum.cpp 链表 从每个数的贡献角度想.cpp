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
using namespace std;

const int maxn = 500000 + 100;
//const int maxn = 100;
typedef long long LL;

struct P {
    int pre, nx;
};

P p[maxn];
int a[maxn];
int pos[maxn];
LL L[100], R[100];


int main() {
//    freopen("data.in", "r", stdin);
    int T; scanf("%d",&T);
    while (T--) {
        int n, k; scanf("%d%d",&n,&k);
        for (int i = 1; i <= n; i ++) {
            int x; scanf("%d",&x);
            pos[x] = i;
        }
        for (int i = 1; i <= n; i ++) {
            p[i].nx = i+1; p[i].pre = i-1;
        }
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        LL res = 0;
        for (int i = 1; i <= n; i ++) { // i : num
            int l = pos[i], r = pos[i];
            L[0] = l, R[0] = l;
            int mxl;
            for (mxl = 1; mxl <= k - 1; mxl ++) {
                l = p[l].pre;
                if (l == 0) break;
                L[mxl] = l;
            }
            L[mxl] = p[L[mxl-1]].pre;
            int mxr;
            for (mxr = 1; mxr <= k - 1; mxr ++) {
                r = p[r].nx;
                if (r == n + 1) break;
                R[mxr] = r;
            }
            R[mxr] = p[R[mxr-1]].nx;
            
            for (int j = 0; j < mxl; j ++) {
                int x = k - 1 - j;
                if (x >= mxr) continue;
                res += (L[j] - L[j+1]) * (R[x+1] - R[x]) * i;
            }
            int x = pos[i];
            p[p[x].pre].nx = p[x].nx;
            p[p[x].nx].pre = p[x].pre;
        }
        printf("%lld\n",res);
    }
    return 0;
}