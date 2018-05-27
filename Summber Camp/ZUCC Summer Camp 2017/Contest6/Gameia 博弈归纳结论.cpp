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
#include <ctime>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;

typedef long long LL;

const int maxn = 1111;
vector<int> G[maxn];
bool vis[maxn];
int odd[maxn];

void init(int n) {
    for (int i = 1; i <= n; i ++) G[i].clear();
}

bool dfs(int x) {
    vis[x] = 1;
    int cnt = 0;
    bool flag = 1;
    for (int i = 0; i < G[x].size(); i ++) {
        int to = G[x][i];
        if (vis[to]) continue;
        flag = (flag && dfs(to));
        if (odd[to] == 1) cnt ++;
    }
    if (cnt < 2) odd[x] = cnt ^ 1;
    if (cnt >= 2) return false;
    return flag;
}

bool check(int n, int k) {
    if (n % 2 || k < (n / 2) - 1) return false;
//    if (!(n % 2 == 0 && k >= (n / 2) - 1))
//        return false;
    MS(vis, 0);
    MS(odd, 0);
    return dfs(1);
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, k; scanf("%d%d",&n,&k);
        init(n);
        for (int i = 1; i < n; i ++) {
            int x; scanf("%d",&x);
            G[x].push_back(i+1);
        }
        if (check(n, k)) puts("Bob");
        else puts("Alice");
    }
    return 0;
}