//
//  main.cpp
//  3946 Highway Project（Dijkstra）
//
//  Created by czf on 16/4/24.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const ll maxn = 100000 + 100;
const ll inf = 0xfffffffffffffff;


ll n, m, d[maxn], c[maxn];

struct Edge {
    ll from, to, dist, cost;
};

struct P {
    ll num, d;
    bool operator > (const P &rhs) const {
        return d > rhs.d;
    }
};

vector<ll> G[maxn];
vector<Edge> edges;

void Addedge(ll from, ll to, ll dist, ll cost) {
    edges.push_back((Edge){from, to, dist, cost});
    ll m = (ll)edges.size() - 1;
    G[from].push_back(m);
}

void dij(ll star) {
    for (ll i = 0; i < n; i ++) d[i] = inf, c[i] = inf;
    d[star] = c[star] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push((P){0, 0});
    while (!q.empty()) {
        P cur = q.top(); q.pop();
        if (cur.d != d[cur.num]) continue;
        for (ll i = 0; i < G[cur.num].size(); i ++) {
            Edge &e = edges[G[cur.num][i]];
            ll from = e.from, to = e.to, dist = e.dist, cost = e.cost;
            if (d[to] > d[from] + dist) {
                d[to] = d[from] + dist;
                c[to] = cost;
                q.push((P){to, d[to]});
            } else if (d[to] == d[from] + dist) {
                c[to] = min(c[to], cost);
            }
        }
    }
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        ll res1 = 0, res2 = 0;
        scanf("%lld%lld",&n,&m);
        for (ll i = 0; i < m; i ++) {
            ll from, to, dist, cost;
            scanf("%lld%lld%lld%lld",&from,&to,&dist,&cost);
            Addedge(from, to, dist, cost);
            Addedge(to, from, dist, cost);
        }
        dij(0);
        for (ll i = 1; i < n; i ++) {
            res1 += d[i];
            res2 += c[i];
        }
        printf("%lld %lld\n",res1,res2);
        edges.clear();
        for (ll i = 0; i < maxn; i ++) G[i].clear();
    }
    return 0;
}
