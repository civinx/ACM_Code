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
#define pb push_back
#define MS(x, y) memset(x, y, sizeof(x))
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;
struct AC_auto {
    static const int MAXN = 100000 + 10;
    //    static const int MAXN = 100;
    static const int SIZE = 26;
    int ch[MAXN][SIZE], fail[MAXN], val[MAXN];
    int root, sz;
    
    int newnode() {
        MS(ch[sz], -1);
        val[sz] = 0;
        return sz++;
    }
    
    void init() {
        sz = 0;
        newnode();
    }
    
    int getid(char c) {
        return c - 'a';
    }
    
    void insert(string & s) {
        int len = s.size();
        int cur = root;
        for (int i = 0; i < len; i ++) {
            int id = getid(s[i]);
            if (ch[cur][id] == -1) {
                ch[cur][id] = newnode();
            }
            cur = ch[cur][id];
        }
        val[cur] ++;
    }
    
    void build() {
        queue<int> q;
        fail[root] = root;
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
    
    int query(string & s) {
        int len = s.size();
        int cur = root;
        int ret = 0;
        for (int i = 0; i < len; i ++) {
            int id = getid(s[i]);
            cur = ch[cur][id];
            int temp = cur;
            while (temp != root) {
                ret += val[temp];
                val[temp] = 0;
                temp = fail[temp];
            }
        }
        return ret;
    }
}AC;

const int maxn = 100000 + 100;

string s[maxn];

int check(int n, int mx) {
    string pre = ""; int cnt = 0;
    int ret = -1;
    for (int i = 0; i < n; i ++) {
        if (s[i].size() == mx) {
            if (!cnt) {
                ret = i;
                pre = s[i];
                cnt ++;
            } else {
                if (s[i] != pre) return -1;
            }
        }
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int mx =  0;
        for (int i = 0; i < n; i ++) {
            cin >> s[i];
            mx = max(mx, (int)s[i].size());
        }
        int st = check(n, mx);
        if (st == -1) {
            cout << "No\n";
            continue;
        }
        AC.init();
        for (int i = 0; i < n; i ++) {
            AC.insert(s[i]);
        }
        AC.build();
        int res = AC.query(s[st]);
       // printf("res = %d\n",res);
        if (res == n) {
            cout << s[st] << '\n';
        } else {
            cout << "No\n";
        }
    }
    return 0;
}