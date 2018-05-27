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
#define INIT int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;

const int maxn = 100000 + 100;
const LL INF = 0x3f3f3f3f3f3f3f3f;


namespace SecShort {
    LL d1[maxn], d2[maxn];
    struct Edge {
        int from, to; LL cost;
    };
    vector<int> G[maxn];
    vector<Edge> edges;
    
    void init(int n) {
        for (int i = 1; i <= n; i ++) G[i].clear();
        edges.clear();
        MS(d1, 0x3f);
        MS(d2, 0x3f);
    }
    
    void AddEdge(int from, int to, LL cost) {
        edges.push_back(Edge{from, to, cost});
        int m = (int)edges.size()-1;
        G[from].push_back(m);
    }
    
    struct P {
        int id; LL dist;
        bool operator > (const P & rhs) const {
            return dist > rhs.dist;
        }
    };
    
    void solve(int s) {
        d1[s] = 0;
        priority_queue<P, vector<P>, greater<P> > q;
        q.push((P){s, 0});
        while (!q.empty()) {
            P cur = q.top(); q.pop();
            if (cur.dist > d2[cur.id]) continue;
            for (int i = 0; i < G[cur.id].size(); i ++) {
                Edge & e = edges[G[cur.id][i]];
                LL dist = cur.dist + e.cost;
                if (dist < d1[e.to]) {
                    swap(dist, d1[e.to]);
                    q.push(P{e.to, d1[e.to]});
                }
                if (dist < d2[e.to]) {
                    d2[e.to] = dist;
                    q.push(P{e.to, d2[e.to]});
                }
            }
        }
    }
};

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, m; scanf("%d%d",&n,&m);
        SecShort::init(n);
        for (int i = 0; i < m; i ++) {
            int u, v; LL cost; scanf("%d%d%lld",&u,&v,&cost);
            SecShort::AddEdge(u, v, cost);
            SecShort::AddEdge(v, u, cost);
        }
        SecShort::solve(1);
        printf("%lld\n",SecShort::d2[n]);
    }
    return 0;
}
