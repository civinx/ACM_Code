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

const int maxn = 5e4 + 100;
const double pi = acos(-1);
const double eps = 1e-6;

struct Point {
    double x, y;
    LL val;
    double angle;
};

Point a[maxn];

double getAngle(double x, double y) {
    if (x == 0){
        if (y > 0) return pi / 2;
        else return 3 * pi / 2;
    }
    if (x > 0 && y >= 0) return atan(y/x);
    if (x < 0 && y >= 0) return pi + atan(y/x);
    if (x < 0 && y < 0) return pi + atan(y/x);
    if (x > 0 && y < 0) return 2 * pi + atan(y/x);
    return -1;
}

bool cmp(const Point & p1, const Point & p2) {
    return p1.angle < p2.angle;
}

LL sum[maxn];
double ang[maxn];

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        for (int i = 1; i <= n; i ++) {
            scanf("%lf%lf%lld",&a[i].x,&a[i].y,&a[i].val);
            a[i].angle = getAngle(a[i].x, a[i].y);
            if (a[i].angle == -1) {
                int zero = 0;
                int x = 5 / zero;
            }
        }
        sort(a+1, a + n + 1, cmp);
        for (int i = 1; i <= n; i ++) {
            sum[i] = sum[i-1] + a[i].val;
            ang[i] = a[i].angle;
        }
        LL res = 0;
        for (int i = 1; i <= n; i ++) {
            double fa = 0;
            if (a[i].angle < pi) {
                fa = a[i].angle + pi;
                int pos = (int)(lower_bound(ang+1, ang+1+n, fa) - ang);
                LL left = sum[pos-1] - sum[i-1];
                LL right = sum[n] - left;
                LL temp = left * right;
                res = max(res, temp);
            } else {
                fa = a[i].angle - pi;
                int pos = (int)(lower_bound(ang+1, ang+1+n, fa) - ang);
                LL left = sum[i-1] - sum[pos-1];
                LL right = sum[n] - left;
                LL temp = left * right;
                res = max(res, temp);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}