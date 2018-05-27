#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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

namespace FastIO {
    char buf[100000],*p1=buf,*p2=buf;
    inline char nc(){
        return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
    }
    inline bool rea(int & x){
        char c=nc();x=0;
        if(c==EOF) return false;
        for(;!isdigit(c);c=nc());
        for(;isdigit(c);x=x*10+c-'0',c=nc());
        return true;
    }
    inline bool rea(LL & x){
        char c=nc();x=0;
        if(c==EOF) return false;
        for(;!isdigit(c);c=nc());
        for(;isdigit(c);x=x*10+c-'0',c=nc());
        return true;
    }
}

const int maxn = 100000 + 100;
//const int maxn = 10;

int n, k;
vector<int> G[maxn];
int fa[maxn];
bool vis[maxn];

int cnt = 0;

void dfs(int x) {
    if (G[x].size() == 0 && !vis[fa[x]]) {
        cnt ++;
        vis[x] = vis[fa[x]] = 1;
        return;
    }
    for (int to : G[x]) {
        dfs(to);
    }
    if (x != 1 && !vis[x] && !vis[fa[x]]) {
        cnt ++;
        vis[x] = vis[fa[x]] = 1;
    }
}

int main() {
    int T; FastIO::rea(T);
    while (T--) {
        FastIO::rea(n); FastIO::rea(k);
        for (int i = 1; i <= n; i ++) G[i].clear();
        for (int i = 2; i <= n; i ++) {
            int x; FastIO::rea(x);
            G[x].push_back(i);
            fa[i] = x;
        }
        MS(vis, 0);
        cnt = 0;
        dfs(1);
        int res = 0;
        if (cnt * 2 >= k) res = (k + 1) / 2;
        else res = cnt + (k - 2 * cnt);
        printf("%d\n",res);
    }
    return 0;
}
