#include <bits/stdc++.h>
using namespace std;

#define lson root << 1, l, mid
#define rson root << 1 | 1, mid + 1, r

typedef long long LL;
typedef long double LB;

const double pi = acos(-1.0);
const int N = 1e3 + 9;
const int M = 1e5 + 9;
//const LL MOD = 998244353;
const LL MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int T, n, k;

struct Num {
    int val;
    int op;
};

Num a[N];

int main() {
    
    int N, L, D;
    
    for (scanf("%d", &T); T --;){
        N = L = D = 0;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i].val);
        for (int i = 1; i <= n; i ++) {
            string s; cin >> s;
            if (s[0] == 'N') a[i].op = 0, N += a[i].val;
            if (s[0] == 'L') a[i].op = 1, L += a[i].val;
            if (s[0] == 'D') a[i].op = -1, D -= a[i].val;
        }
        
        //if (abs(k) > n * (n - 1) / 2 + 1) {printf("no\n");continue;}
        if (k > L + N || k < D - N) {printf("no\n");continue;}
        printf("yes\n");
    }
    
    return 0;
}