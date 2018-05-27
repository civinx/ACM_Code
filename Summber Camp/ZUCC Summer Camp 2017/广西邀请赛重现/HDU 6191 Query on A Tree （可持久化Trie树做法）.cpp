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

const int maxn = 100000 + 100;
const int maxbit = 31;
//const int maxn = 10;

vector<int> G[maxn];

struct Node {
    int son[2];
    int cnt = 0;
    Node () {
        son[0] = son[1] = cnt = 0;
    }
}ch[maxn * 35];

int val[maxn], L[maxn], R[maxn], seq[maxn], root[maxn];

void init(int n) {
    for (int i = 1; i <= n; i ++) G[i].clear();
}

int cnt;

void dfs(int x) {
    L[x] = ++cnt; seq[cnt] = x;
    for (int to : G[x]) {
        dfs(to);
    }
    R[x] = cnt;
}

void insert(int fa, int & cur, int x, int pos) {
    ch[cur=++cnt] = ch[fa]; ch[cur].cnt ++;
    if (pos < 0) return;
    int num = (x >> pos) & 1;
    insert(ch[fa].son[num], ch[cur].son[num], x, pos-1);
}

int query(int l, int r, int x, int pos, int ret = 0) {
    if (pos < 0) return ret;
    int num = (x >> pos) & 1;
    if (ch[ch[r].son[num^1]].cnt - ch[ch[l].son[num^1]].cnt > 0) {
        return query(ch[l].son[num^1], ch[r].son[num^1], x, pos-1, ret + (1<<pos));
    } else {
        return query(ch[l].son[num], ch[r].son[num], x, pos-1, ret);
    }
}

int main() {
    int n, q;
    while (scanf("%d%d",&n,&q) == 2) {
        init(n);
        for (int i = 1; i <= n; i ++) scanf("%d",&val[i]);
        for (int i = 2; i <= n; i ++) {
            int x; scanf("%d",&x);
            G[x].push_back(i);
        }
        cnt = 0;
        dfs(1);
        cnt = 0;
        for (int i = 1; i <= n; i ++) {
            insert(root[i-1], root[i], val[seq[i]], maxbit);
        }
        while (q--) {
            int u, x; scanf("%d%d",&u,&x);
            int res = query(root[L[u]-1], root[R[u]], x, maxbit);
            printf("%d\n",res);
        }
    }
    return 0;
}
