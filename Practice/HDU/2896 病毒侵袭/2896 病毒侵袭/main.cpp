//
//  main.cpp
//  2896 病毒侵袭
//
//  Created by czf on 2017/8/30.
//  Copyright © 2017年 czf. All rights reserved.
//

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

struct AC_auto {
    static const int MAXN = 100000 + 100;
    static const int SIZE = 130;
    
    int ch[MAXN][SIZE], fail[MAXN], val[MAXN];
    int root, sz;
    
    int newnoede() {
        MS(ch[sz], -1);
        val[sz] = 0;
        return sz++;
    }
    
    void init() {
        sz = 0;
        root = newnoede();
        fail[root] = root;
    }
    
    void insert(char * s, int x) {
        int len = (int)strlen(s);
        int cur = root;
        for (int i = 0; i < len; i ++) {
            char c = s[i]; int id = c;
            if (ch[cur][id] == -1) {
                ch[cur][id] = newnoede();
            }
            cur = ch[cur][id];
        }
        val[cur] = x;
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
    
    set<int> query(char * s) {
        set<int> ret;
        int cur = root;
        int len = (int)strlen(s);
        for (int i = 0; i < len; i ++) {
            char c = s[i]; int id = c;
            cur = ch[cur][id];
            int temp = cur;
            while (temp != root) {
                if (val[temp]) ret.insert(val[temp]);
                temp = fail[temp];
            }
        }
        return ret;
    }
}AC;

const int maxn = 10000 + 100;
char s[maxn];

int main() {
    //    int T; scanf("%d",&T);
    int n;
    while (scanf("%d",&n) == 1) {
        AC.init();
        for (int i = 1; i <= n; i ++) {
            scanf("%s",s);
            AC.insert(s, i);
        }
        AC.build();
        int m; scanf("%d",&m);
        int cnt = 0;
        for (int i = 1; i <= m; i ++) {
            scanf("%s",s);
            set<int> res = AC.query(s);
            if (res.size()) {
                cnt ++;
                printf("web %d:",i);
                for (int x : res) {
                    printf(" %d",x);
                }
                printf("\n");
            }
        }
        printf("total: %d\n",cnt);
    }
    return 0;
}
