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

const int maxn = 1111;
vector<int> G[maxn];
bool vis[maxn];
bool ok[maxn][maxn];

void init(int n) {
    for (int i = 1; i <= n; i ++) G[i].clear();
    MS(ok, 0);
}

int cnt, st;

void dfs(int x) {
    vis[x] = 1;
    if (ok[st][x] == 0 && ok[x][st] == 0 && st != x) {
        cnt ++;
    }
    ok[st][x] = 1;
    for (int i = 0; i < G[x].size(); i ++) {
        int to = G[x][i];
        if (!vis[to]) {
            dfs(to);
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, m; scanf("%d%d",&n,&m);
        init(n);
        for (int i = 0; i < m; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        bool flag = 1;
        cnt = 0;
        for (int i = 1; i <= n; i ++) {
            st = i;
            MS(vis, 0);
            dfs(i);
        }
        if (cnt != n * (n-1) / 2) {
            flag = 0;
        }
        if (flag) {
            printf("I love you my love and our love save us!\n");
        } else {
            printf("Light my fire!\n");
        }
    }
    return 0;
}