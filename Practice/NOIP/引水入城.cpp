//
// Created by CZF on 2017/2/13.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

const int maxn = 555;
const int INF = 0x3f3f3f3f;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
struct P {
    int l, r;
    P () {
        l = INF, r = 0;
    }
};

int a[maxn][maxn], dp[maxn], n, m;
P p[maxn];
bool vis[maxn], used[maxn][maxn];

void bfs(int id) {
    queue<pair<int, int> > q;
    q.push(make_pair(1, id));
    while (!q.empty()) {
        pair<int, int> cur = make_pair(q.front().first, q.front().second); q.pop();
        if (used[cur.first][cur.second]) continue;
        if (cur.first == n) {
            vis[cur.second] = 1;
        }
        for (int i = 0; i < 4; i ++) {
            int x = cur.first + dir[i][0];
            int y = cur.second + dir[i][1];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (a[x][y] < a[cur.first][cur.second]) {
                q.push(make_pair(x, y));
            }
        }
        used[cur.first][cur.second] = 1;
    }
}

void dfs(P &val, int x, int y) {
    used[x][y] = 1;
    if (x == n) {
        val.l = min(val.l, y);
        val.r = max(val.r, y);
    }
    for (int i = 0; i < 4; i ++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if (a[x][y] <= a[xx][yy]) continue;
        if (!used[xx][yy]) dfs(val, xx, yy);
    }
}

int solve() {
    for (int i = 1; i <= m; i ++) {
        memset(used, 0, sizeof(used));
        dfs(p[i], 1, i);
    }
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (p[j].l > p[j].r) continue;
            if (p[j].l <= i && i <= p[j].r) {
                int L = p[j].l - 1 < 0 ? 0 : p[j].l - 1;
                dp[i] = min(dp[i], dp[L] + 1);
            }
        }
    }
    return dp[m];
}
int main() {
    //std::ios::sync_with_stdio(false);
//    cin >> n >> m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
//            cin >> a[i][j];
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 1; i <= m; i ++) bfs(i);


    int cnt = 0;
    for (int i = 1; i <= m; i ++) if (!vis[i]) cnt ++;
//    cnt ? (cout << 0 << '\n' << cnt << '\n') : (cout << 1 << '\n' << solve() << '\n');
    if (cnt) printf("0\n%d\n",cnt);
    else printf("1\n%d\n",solve());
    return 0;
}