#include <bits/stdc++.h>
using namespace std;

#define lson root << 1, l, mid
#define rson root << 1 | 1, mid + 1, r

typedef long long LL;
typedef long double LB;

const int N = 1e5 + 9;
const int M = 1e5 + 9;
//const LL MOD = 998244353;
const LL MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m;

bool vis[1000009];

int main() {

    int n;
    
    int T;
    
    for (scanf("%d", &T); T --;){
        scanf("%d", &n);
        if (n & 1) printf("%d\n", n / 2 + 2);
        else printf("%d\n", n / 2 + 1);
    }
    /*
    for (int i = 1; i <= 100; i ++){
        int count = 0;
        memset(vis, false, sizeof(vis));
        for (int j = 1; j <= i + 1; j ++){
            if (!vis[i % j]){
                vis[i % j] = true;
                count ++;
            }
        }
        printf("%d %d\n", i, count);
    }*/

    return 0;
}

// 16 4 2 4 2