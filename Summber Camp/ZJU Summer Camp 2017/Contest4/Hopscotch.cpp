#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long LL;

const LL INF = 1e18;
const int maxn = 100000 + 100;

struct P {
    int id;
    LL val;
};

vector<int> G[maxn];
LL d[maxn], a[maxn];
int deg[maxn];
int n, m;

void init() {
    for (int i = 0; i < n; i ++) G[i].clear();
    for (int i = 0; i < n; i ++) d[i] = -INF;
    memset(deg, 0, sizeof(deg));
}

int main()  {
    //    printf("%d\n",-INF);
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        init();
        for (int i = 0; i < n; i ++) {
            scanf("%lld",&a[i]);
        }
        for (int i = 0; i < m; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            deg[v] ++;
        }
        queue<P> q;
        LL res = -INF;
        for (int i = 0; i < n; i ++) {
            if (deg[i] == 0) {
                q.push((P){i, a[i]});
                res = max(res, a[i]);
                d[i] = a[i];
            }
        }
        while (!q.empty()) {
            P cur = q.front(); q.pop();
            int u = cur.id;
            for (int i = 0; i < G[u].size(); i ++) {
                int to = G[u][i];
                if (cur.val < 0) {
                    d[to] = max(a[to], d[to]);
                    res = max(res, d[to]);
                } else if (cur.val + a[to] > d[to]) {
                    d[to] = cur.val + a[to];
                    res = max(res, d[to]);
                }
                deg[to] --;
                if (deg[to] == 0) {
                    q.push((P){to, d[to]});
                }
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
