#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 100, limit = 50;
vector<int> G[maxn], b, w;
vector<pair<int, int> > pii;
bool vis[maxn];

void init(int n) {
    for (int i = 1; i <= n; i ++) G[i].clear();
    b.clear();
    w.clear();
    pii.clear();
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, m, k; scanf("%d%d%d",&n,&m,&k);
        init(n);
        for (int i = 0; i < k; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            
        }
        for (int i = 1; i <= n; i ++) {
            if (G[i].size() > lim) b.push_back(i);
            else w.push_back(i);
            sort(G[i].begin(), G[i].end());
        }
        LL res = 0, tot = 0;
        for (int u : b) {
            memset(vis, 0, sizeof(vis));
            for (int v : G[u]) vis[v] = 1;
            for (int i = 1; i <= n; i ++) {
                if (i == u) continue;
                tot = 0;
                for (int v : G[i]) if (vis[v]) tot ++;
                res += tot * (tot - 1) / 2;
            }
        }
        for (int i = 0; i < b.size(); i ++) {
            int u = b[i];
            memset(vis, 0, sizeof(vis));
            for (int v : G[u]) vis[v] = 1;
            for (int j = i+1; j < b.size(); j ++) {
                int x = b[j];
                tot = 0;
                for (int v : G[x]) if (vis[v]) tot ++;
                res -= tot * (tot - 1) / 2;
            }
        }
        for (int u : w) {
            for (int i = 0; i < G[u].size(); i ++) {
                for (int j = i + 1; j < G[u].size(); j ++) {
//                    pii.emplace_back(pair<int, int>(G[u][i], G[u][j]));
                    pii.push_back(make_pair(G[u][i], G[u][j]));
                }
            }
        }
        tot = 0;
        sort(pii.begin(), pii.end());
        for (int i = 0; i < pii.size(); i ++) {
            if (i == 0 || pii[i] == pii[i-1]) tot ++;
            else {
                res += tot * (tot - 1) / 2;
                tot = 1;
            }
        }
        res += tot * (tot - 1) / 2;
        printf("%lld\n",res);
    }
    return 0;
}