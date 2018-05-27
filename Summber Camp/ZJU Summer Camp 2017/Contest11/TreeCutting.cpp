#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;

const int maxn = 100000 + 100;
//const int maxn = 10;

struct Edge {
    int from, to;
};

int fa[maxn], root[maxn], sz[maxn];
int n, k, rt, mxd;
vector<int> G[maxn];
vector<Edge> edges;
vector<int> dep[maxn];

void init() {
    for (int i = 1; i <= n; i ++) root[i] = i, sz[i] = 1, G[i].clear(), dep[i].clear();
    MS(fa, 0);
    edges.clear();
    mxd = 0;
}



void dfs(int x, int f, int d) {
    fa[x] = f;
    dep[d].push_back(x);
    mxd = max(mxd, d);
    if (G[x].size() == 1 && x != rt) {
        return;
    }
    for (int i = 0; i < G[x].size(); i ++) {
        int to = G[x][i];
        if (to == f) continue;
        dfs(to, x, d + 1);
    }
}

int find(int x) {
    return x == root[x] ? x : root[x] = find(root[x]);
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&k);
        init();
        for (int i = 0; i < n-1; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for (int i = 1; i <= n; i ++) {
            if (G[i].size() == 1) {
                rt = i;
                break;
            }
        }
        dfs(rt, 0, 1);
        for (int i = mxd; i > 0; i --) {
            for (int j = 0; j < dep[i].size(); j ++) {
                int x = dep[i][j];
                int set_id = find(x);
                if (sz[set_id] == k) {
                    continue;
                }
                if (sz[set_id] < k) {
                    int f = fa[x];
                    if (f == 0) continue;
                    int f_set_id = find(f);
                    if (sz[f_set_id] + sz[set_id] <= k) {
                        root[set_id] = root[f_set_id];
                        sz[f_set_id] += sz[set_id];
                    }
                }
            }
        }
        bool flag = 1;
        for (int i = 1; i <= n; i ++) {
            int x = find(i);
            if (sz[x] != k) {
                flag = 0;
                break;
            }
        }
        if (flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
    
}