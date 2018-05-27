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

const int maxn = 10000000 + 100;
//const int maxn = 100;

LL a[maxn], b[maxn];

int main() {
    int T; scanf("%d",&T);
    LL l = 0;
    for (int i = 1; i <= T; i ++) {
        scanf("%lld",&b[i]);
        l = max(l, b[i]);
    }
    a[1] = 1;
    a[2] = 2;
    LL right = 2;
    for (int i = 2; i <= l+1; i ++) {
        for (LL j = right+1; j <= right+a[i]-1;j ++) {
            a[j] = a[j-1];
        }
        right = right + a[i];
        if (a[right-1] == 1) {
            a[right] = 2;
        } else {
            a[right] = 1;
        }
        if (right > l + 2) {
            break;
        }
        
    }
    for (int i = 1; i <= T; i ++) {
        printf("%lld\n",a[b[i]]);
    }
    return 0;
}