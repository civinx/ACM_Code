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


namespace KShort {
    LL h[maxn];
    
    struct Edge {
        int from, to; LL cost;
    };
    vector<int> G[maxn];
    vector<Edge> edges;
    
    int n;
    void init(int n) {
        KShort::n = n;
        for (int i = 1; i <= n; i ++) G[i].clear();
        edges.clear();
    }
    
    void AddEdge(int from, int to, LL cost) {
        edges.push_back(Edge{from, to, cost});
        int m = (int)edges.size()-1;
        G[from].push_back(m);
    }

    
    void dijkstra(int s) {
        struct P {
            int id; LL val;
            bool operator > (const P & rhs) const {
                return val > rhs.val;
            }
        };
        for (int i = 1; i <= n; i ++) h[i] = INF;
        h[s] = 0;
        priority_queue<P, vector<P>, greater<P> > q;
        q.push((P){s, 0});
        while (!q.empty()) {
            P cur = q.top(); q.pop();
            if (cur.val != h[cur.id]) continue;
            for (int i = 0; i < G[cur.id].size(); i ++) {
                Edge & e = edges[G[cur.id][i]];
                int from = e.from, to = e.to; LL cost = e.cost;
                if (h[to] > h[from] + e.cost) {
                    h[to] = h[from] + cost;
                    q.push((P){to, h[to]});
                }
            }
        }
    }
    
    LL solve(int s, int t, int k) {
        struct P {
            int id; LL g, h;
            bool operator > (const P & rhs) const {
                return g + h > rhs.g + rhs.h;
            }
        };
        dijkstra(t);
        priority_queue<P, vector<P>, greater<P> > q;
        q.push(P{s, 0, h[s]});
        int cnt = 0;
        while (!q.empty()) {
            P cur = q.top(); q.pop();
            if (cur.id == t) {
                cnt ++;
                if (cnt == k) return cur.g;
            }
            for (int i = 0; i < G[cur.id].size(); i ++) {
                Edge & e = edges[G[cur.id][i]];
                q.push(P{e.to, cur.g+e.cost, h[e.to]});
            }
        }
        return -1;
    }
};

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, m; scanf("%d%d",&n,&m);
        KShort::init(n);
        for (int i = 0; i < m; i ++) {
            int u, v; LL cost; scanf("%d%d%lld",&u,&v,&cost);
            KShort::AddEdge(u, v, cost);
            KShort::AddEdge(v, u, cost);
        }
        LL res = KShort::solve(1, n, 2);
        printf("%lld\n",res);
    }
    return 0;
}
