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

int solve(int n, int m) {
    if (m == 1) {
        return (n + 1) / 2;
    }
    if (n < m) {
        return n;
    }
    if (n < 2 * m) {
        return m;
    }
    return (n + 1) / 2;
//    int ret = 0;
//    int temp = n;
//    ret += m;
//    n -= m;
//    int k = 2 * m - 1;
//    int cnt = n / k;
//    ret += (cnt / 2) * k;
//    if (cnt & 1) {
//        ret += (n % k);
//    }
//    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, m; scanf("%d%d",&n,&m);
        printf("%d\n",solve(n, m));
    }
    return 0;
}