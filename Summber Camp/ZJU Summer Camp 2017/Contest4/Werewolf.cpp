#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 2222;
vector<int> G[maxn];
vector<char> res;
bool vis[maxn];
int n, m;

void init() {
    res.clear();
    for (int i = 1; i <= n*2; i ++) G[i].clear();
}

inline int getF(int x) {
    return x > n ? x - n : x + n;
}

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = 1;
    for (int v : G[x]) dfs(v);
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        init();
        for (int i = 0; i < m; i ++) {
            int x, y; char opx, opy; scanf("%d %c %d %c",&x,&opx,&y,&opy);
            if (opx == 'N') x = getF(x);
            if (opy == 'N') y = getF(y);
            G[getF(x)].push_back(y);
            G[getF(y)].push_back(x);
        }
        bool flag = 1;
        for (int i = 1; i <= n; i ++) {
            memset(vis, 0, sizeof(vis));
            dfs(i);
            bool f1 = vis[i+n];
            memset(vis, 0, sizeof(vis));
            dfs(i+n);
            bool f2 = vis[i];
            if (f1 && f2) {
                flag = 0;
                break;
            }
            if (f1) res.push_back('N');
            if (f2) res.push_back('Y');
            if (!f1 && !f2) res.push_back('?');
        }
        if (!flag) {
            printf("IMPOSSIBLE\n");
        } else {
            for (int i = 0; i < res.size(); i ++) {
                printf("%c",res[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
