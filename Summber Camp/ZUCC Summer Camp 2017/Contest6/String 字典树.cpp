#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;

const int MAXN = 500000+100;
//const int MAXN = 100;
const int MAXM = 26;
struct Trie {
    int ch[MAXN<<1][MAXM];
    int rt;
    int sz;
    vector<int> G[MAXN<<1];
    
    void init() {
        sz = 0;
        rt = newNode();
        for (int i = 0; i < MAXN<<1; i ++) G[i].clear();
    }
    
    int newNode() {
        MS(ch[sz], 0);
        return sz ++;
    }
    
    void insert(char * s) {
        int len = (int)strlen(s);
        int u = rt;
        for (int i = 0; i < len; i ++) {
            int num = s[i] - 'a';
            if (ch[u][num] == 0) {
                ch[u][num] = newNode();
            }
            u = ch[u][num];
            G[u].push_back(len/2);
        }
    }
    
    void sortG() {
        for (int i = 1; i < sz; i ++) {
            sort(G[i].begin(), G[i].end());
        }
    }
    
    int get(int id, int x) {
        int sub = (int)(lower_bound(G[id].begin(), G[id].end(), x) - G[id].begin());
        return (int)G[id].size() - sub;
    }
} T;

char s0[MAXN], s1[MAXN], s2[MAXN<<1];

int getString() {
    int len0 = (int)strlen(s0), len1 = (int)strlen(s1);
    int len = max(len0, len1);
    for (int i = 0; i < len; i ++) {
        s2[i*2] = i < len0 ? s0[i] : '*';
        s2[i*2+1] = i < len1 ? s1[len1-1-i] : '*';
    }
    s2[len<<1] = '\0';
    return len << 1;
}

int main() {
    int _; scanf("%d",&_);
    while (_--) {
        T.init();
        int n, m; scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i ++) {
            scanf("%s",s1); int len = (int)strlen(s1);
            for (int j = 0; j < len; j ++) {
                s2[j*2] = s1[j];
                s2[j*2+1] = s1[len-1-j];
            }
            s2[len<<1] = '\0';
            T.insert(s2);
        }
        T.sortG();
        while (m--) {
            scanf("%s%s",s0,s1);
            int len = getString();
            queue<int> q[2];
            q[0].push(0);
            int id = 0;
            for (int i = 0; i < len; i ++) {
                while (!q[id].empty()) {
                    int cur = q[id].front(); q[id].pop();
                    if (s2[i] != '*') {
                        int need = s2[i] - 'a';
                        if (T.ch[cur][need]) {
                            q[id^1].push(T.ch[cur][need]);
                        }
                    } else {
                        for (int j = 0; j < MAXM; j ++) {
                            if (T.ch[cur][j]) {
                                q[id^1].push(T.ch[cur][j]);
                            }
                        }
                    }
                }
                id ^= 1;
            }
            int res = 0, minLen = (int)(strlen(s0) + strlen(s1));
            while (!q[id].empty()) {
                int cur = q[id].front(); q[id].pop();
                res += T.get(cur, minLen);
            }
            printf("%d\n",res);
        }
    }
    return 0;
}