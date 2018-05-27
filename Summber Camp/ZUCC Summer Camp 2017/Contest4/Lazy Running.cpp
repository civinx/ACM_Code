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

const int maxn = 60000 + 100;
const LL INF = 0x3f3f3f3f3f3f3f3f;

LL path[5][5], d[5][maxn];
LL k, g1, g2, g3, g4, w;

struct P {
    int id;
    LL mod;
    LL dist;
    bool operator > (const P & rhs) const {
        return dist > rhs.dist;
    }
};


void dij(int s) {
    for (int i = 1; i <= 4; i ++) {
        for (int j = 0; j < maxn; j ++) {
            d[i][j] = INF;
        }
    }
    priority_queue<P, vector<P>, greater<P>> q;
    d[2][0] = 0;
    q.push(P{2, 0, 0});
    while (!q.empty()) {
        P cur = q.top(); q.pop();
        if (cur.dist != d[cur.id][cur.mod]) continue;
        for (int i = 1; i <= 4; i ++) {
            if (i == cur.id || path[cur.id][i] == INF) continue;
            LL mod = (cur.dist + path[cur.id][i]) % w;
            if (d[i][mod] > cur.dist + path[cur.id][i]) {
                d[i][mod] = cur.dist + path[cur.id][i];
                q.push(P{i, mod, d[i][mod]});
            }
        }
    }
}

void read() {
    scanf("%lld%lld%lld%lld%lld",&k,&g1,&g2,&g3,&g4);
    for (int i = 1; i <= 4; i ++) {
        for (int j = 1; j <= 4; j ++) {
            path[i][j] = INF;
        }
    }
    path[1][2] = path[2][1] = g1;
    path[2][3] = path[3][2] = g2;
    path[3][4] = path[4][3] = g3;
    path[4][1] = path[1][4] = g4;
    w = min(g1, g2) * 2;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        read();
        dij(2);
        LL res = INF;
        for (int i = 0; i < w; i ++) {
            if (d[2][i] >= k) res = min(res, d[2][i]);
            else {
                LL x = k - d[2][i];
                LL cnt = x / w + 1;
                if (x % w == 0) cnt --;
                res = min(res, d[2][i] + cnt * w);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
