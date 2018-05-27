// #include <algorithm>
// #include <iostream>
// #include <cstring>
// #include <cstdlib>
// #include <string>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <cmath>
// #include <map>
// #include <set>
// #define lson l, mid, rt << 1
// #define rson mid+1, r, rt << 1 | 1
// #define ls rt << 1
// #define rs rt << 1 | 1
// #define MS(x, y) memset(x, y, sizeof(x))
// using namespace std;

// typedef long long LL;

// const int maxn = 65;

// int a[maxn], b[maxn];

// void solve(int x) {
//     for (int i = 0; i < maxn; i ++) b[i] = a[i];
//     for (int i = 0; i < x; i ++) {
//         for (int j = 1; j < maxn; j ++) {
//             b[j] ^= b[j-1];
//         }
//     }
//     for (int i = 0; i < maxn; i ++) {
//         printf("%d%c",b[i],i==maxn-1?'\n':' ');
//     }
//     printf("\n");
// }

// int main() {
//     a[0] = 1;
//     for (int i = 0; i < 10; i ++) {
//         printf("%d: ",i);
//         solve(1<<i);
//     }
//     return 0;
// }

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

const int maxn = 2e5 + 100;

int a[maxn];

int lowbit(int x) {
    return x & (-x);
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, m; scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i ++) scanf("%d",&a[i]);
        while (m) {
            int k = 0;
            while (1 << (k + 1) <= m) k ++;
            int step = (1 << k);
            for (int i = 0; i + step < n; i ++) {
                a[i+step] ^= a[i];
            }
            m -= (1 << k);
        }
        for (int i = 0; i < n; i ++) {
            printf("%d%c",a[i],i==n-1?'\n':' ');
        }
    }
    return 0;
}
