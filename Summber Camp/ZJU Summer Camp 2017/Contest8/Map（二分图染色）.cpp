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
using namespace std;
typedef long long LL;

const int maxn = 1111;

int pos[maxn];

struct Edge {
    int u, v;
};

vector<Edge> edges;

bool check(int l1, int r1, int l2, int r2) {
    if (r2 <= l1 || r1 <= l2) return false;
    if (l1 <= l2 && r2 <= r1) return false;
    if (l2 <= l1 && r1 <= r2) return false;
    return true;
}

vector<int> G[maxn * 5];
int vis[maxn * 5];

bool flag;

void dfs(int x, int c) {
    if (!flag) {
        return;
    }
    vis[x] = c;
    for (int i = 0; i < G[x].size(); i ++) {
        if (!flag) {
            return;
        }
        int to = G[x][i];
        if (vis[to] != -1) {
            if (vis[to] == c) {
                flag = false;
                return ;
            }
        } else {
            dfs(to, c ^ 1);
        }
    }
}

void init(int m) {
    for (int i = 0; i <= m; i ++) G[i].clear();
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        edges.clear();
        int n, m; scanf("%d%d",&n,&m);
        for (int i = 0; i < m; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            edges.push_back(Edge{u, v});
        }
        
        for (int i = 1; i <= n; i ++) {
            int x; scanf("%d",&x);
            pos[x] = i;
        }
        if (m > 3*n-6) {
            printf("NO\n");
            continue;
        }
        init(m);
        for (int i = 0; i < edges.size(); i ++) {
            Edge & e = edges[i];
            if (pos[e.u] > pos[e.v]) {
                swap(e.u, e.v);
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = i + 1; j < m; j ++) {
                Edge & e1 = edges[i];
                Edge & e2 = edges[j];
                if (pos[e1.v] - pos[e1.u] == 1) continue;
                if (pos[e2.v] - pos[e2.u] == 1) continue;
                if (pos[e1.u] == 1 && pos[e1.v] == n) continue;
                if (pos[e2.u] == 1 && pos[e2.v] == n) continue;
                if (check(pos[e1.u], pos[e1.v], pos[e2.u], pos[e2.v])) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        flag = 1;
        memset(vis, -1, sizeof(vis));
        for (int i = 0; i < edges.size(); i ++) {
            if (vis[i] == -1) {
                dfs(i, 0);
            }
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
