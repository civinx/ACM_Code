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
#define FILER freopen("1006.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;

struct AC_auto {
    static const int MAXN = 100000 + 100;
    static const int SIZE = 26;
    
    int ch[MAXN][SIZE], fail[MAXN], val[MAXN], vis[MAXN];
    int root, sz;
    
    int newnode(int dep) {
        MS(ch[sz], -1);
        val[sz] = dep;
        return sz++;
    }
    
    void init() {
        sz = 0;
        root = newnode(0);
        fail[root] = root;
    }
    
    int getid(char c) {
        return c - 'a';
    }
    
    void insert(const string & s) {
        int cur = root;
        for (int i = 0; i < s.size(); i ++) {
            int id = getid(s[i]);
            if (ch[cur][id] == -1) {
                ch[cur][id] = newnode(i+1);
            }
            cur = ch[cur][id];
        }
    }
    
    void build() {
        queue<int> q;
        for (int i = 0; i < SIZE; i ++) {
            int & son = ch[root][i];
            if (son == -1) {
                son = root;
            } else {
                fail[son] = root;
                q.push(son);
            }
        }
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i = 0; i < SIZE; i ++) {
                int & son = ch[cur][i];
                if (son == -1) {
                    son = ch[fail[cur]][i];
                } else {
                    fail[son] = ch[fail[cur]][i];
                    q.push(son);
                }
            }
        }
    }
    
    void query1(const string & s) {
        MS(vis, 0);
        int cur = root;
        for (int i = 0; i < s.size(); i ++) {
            int id = getid(s[i]);
            cur = ch[cur][id];
            int temp = cur;
            while (temp != root) {
                vis[temp] = 1;
                temp = fail[temp];
            }
        }
    }
    
    int query2(const string & s) {
        int cur = root;
        int ret = 0;
        for (int i = 0; i < s.size(); i ++) {
            int id = getid(s[i]);
            cur = ch[cur][id];
            int temp = cur;
            while (temp != root) {
                if (vis[temp]) {
                    ret = max(ret, val[temp]);
                }
                temp = fail[temp];
            }
        }
        return ret;
    }
}AC;

const int maxn = 100000 + 100;
string s[maxn];

int main() {
//    FILER;
//    FILEW;
    int T; scanf("%d",&T);
    while (T--) {
        AC.init();
        int n; scanf("%d",&n);
        for (int i = 1; i <= n; i ++) {
            cin >> s[i];
            AC.insert(s[i]);
        }
        AC.build();
        int q; scanf("%d",&q);
        while (q--) {
            int x, y; scanf("%d%d",&x,&y);
            AC.query1(s[x]);
            printf("%d\n",AC.query2(s[y]));
        }
    }
    return 0;
}
