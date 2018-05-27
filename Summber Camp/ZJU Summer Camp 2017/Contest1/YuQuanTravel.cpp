#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100000 * 2 + 100;

//const int maxn = 100;

int n, m;

vector<int> G[maxn];
bool vis[maxn];
int d[maxn];

void init() {
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i ++) G[i].clear();
}

void dfs(int pre, int x, int step) {
    d[x] = step;
    for (int i = 0; i < G[x].size(); i ++) {
        int to = G[x][i];
        if (to == pre) continue;
        dfs(x, to, step + 1);
    }
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        init();
        for (int i = 0; i < n-1; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        d[1] = 0;
        dfs(0, 1, 0);
        int st = 1;
        for (int i = 2; i <= n; i ++) {
            if (d[i] > d[st]) {
                st = i;
            }
        }
        memset(d, 0, sizeof(d));
        dfs(0, st, 0);
        int g = 0;
        for (int i = 1; i <= n; i ++) {
            g = max(g, d[i]);
        }
        int gn = g + 1;
        while (m --) {
            int x; scanf("%d",&x);
            if (x <= gn) {
                printf("%d\n",x-1);
            } else {
                printf("%d\n",g + (x - gn) * 2);
            }
        }
    }
    return 0;
}
