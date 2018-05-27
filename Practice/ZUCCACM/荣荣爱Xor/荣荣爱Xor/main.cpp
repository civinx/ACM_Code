//
//  main.cpp
//  荣荣爱Xor
//
//  Created by czf on 2017/3/17.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 50000 + 100;
const int MOD = 998244353;
struct Node {
    Node * lson, * rson;
    int value, cnt;
    Node () : lson(NULL), rson(NULL), value(0), cnt(1){};
};

vector<int> G[maxn];
int f[maxn];

Node * build(Node * T, vector<int> & v, int pos) {
    if (T == NULL) T = new Node;
    else T->cnt++;
    if (pos == v.size()) {
        return T;
    }
    if (v[pos] == 0) T->lson = build(T->lson, v, pos+1);
    if (v[pos] == 1) T->rson = build(T->rson, v, pos+1);
    return T;
}

int count(Node * T) {
    if (!T) return 0;
    if (!T->lson && !T->rson) return T->cnt;
    T->value += count(T->lson);
    T->value += count(T->rson);
    return T->value;
}

int solve(Node * T, vector<int> & v, int pos) {
    if (pos == v.size()) {
        return 0;
    }
    int ret = 0;
    if (v[pos] == 0) ret = (ret + solve(T->lson, v, pos+1)) % MOD;
    if (v[pos] == 1) {
        int cnt = 0;
        if (T->lson) cnt = T->lson->value;
//        printf("%d %d\n",f[pos], cnt);
        ret = (ret + (f[pos] * cnt % MOD)) % MOD;
        ret = (ret + solve(T->rson, v, pos+1)) % MOD;
    }
    return ret;
}

void clear(Node * T) {
    if (T == NULL) return;
    clear(T->lson);
    clear(T->rson);
    delete T;
}

void init(int n, Node * T) {
    for (int i = 0; i < n; i ++) G[i].clear();
    clear(T);
}

int main() {
    f[0] = 1; for (int i = 1; i <= 30; i ++) f[i] = f[i-1] * 2 % MOD;
    int t, kase = 0; scanf("%d",&t); Node * T = NULL;
    while (t--) {
        int n; scanf("%d",&n);
        init(n, T);
        T = NULL;
        for (int i = 0; i < n; i ++) {
            int x; scanf("%d",&x);
            int temp = x;
            while (temp) {
                G[i].push_back(temp & 1);
                temp >>= 1;
            }
            while (G[i].size() < 30) G[i].push_back(0);
            T = build(T, G[i], 0);
        }
        count(T);
        int res = 0;
        for (int i = 0; i < n; i ++) res = (res + solve(T, G[i], 0)) % MOD;
        printf("Case #%d: %d\n",++kase,res*2%MOD);
    }
    return 0;
}
