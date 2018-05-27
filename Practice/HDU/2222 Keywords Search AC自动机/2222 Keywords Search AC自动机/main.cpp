//
//  main.cpp
//  2222 Keywords Search AC自动机
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
    static const int MAXN = 500000 + 100;
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
    
    void insert(char * s) {
        int len = (int)strlen(s);
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
    
    // 有几个单词在文章出现过
    int query(char * s) {
        int len = (int)strlen(s);
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

const int maxn = 1000000 + 10;
char s[maxn];
int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        AC.init();
        for (int i = 0; i < n; i ++) {
            scanf("%s",s);
            AC.insert(s);
        }
        AC.build();
        scanf("%s",s);
        int res = AC.query(s);
        printf("%d\n",res);
    }
    return 0;
}
