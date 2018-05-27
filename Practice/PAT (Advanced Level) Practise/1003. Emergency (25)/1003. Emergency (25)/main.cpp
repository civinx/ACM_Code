//
//  main.cpp
//  1003. Emergency (25)
//
//  Created by czf on 16/4/28.
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

struct Edge {
    ll from, to, dist;
};

struct Hp {
    ll num, d;
    bool operator < (const Hp &rhs) const {
        return d > rhs.d;
    }
};

vector<ll> G[maxn];//每个点连着的边的编号
vector<Edge> edge;//边集
ll d[maxn], c[maxn], num[maxn]; //d从出发点到达的最短距离,c从出发点到达最短距离的情况下点权值总和的最大值,num每个点的权值

void AddEdge(ll from, ll to, ll dist) {
    edge.push_back((Edge){from,to,dist});
    int m = edge.size() - 1;
    G[from].push_back(m);
}

void Dij(ll star, ll n) {
    for (int i = 0; i < n; i ++) d[i] = inf, c[i] = 0;
    d[star] = 0;
    c[star] = num[star];
    priority_queue<Hp> q; q.push((Hp){star,0});
    while (!q.empty()) {
        Hp cur = q.top(); q.pop();
        if (cur.d != d[cur.num]) continue;
        for (int i = 0; i < G[cur.num].size(); i ++) {
            Edge &e = edge[G[cur.num][i]];
            ll from = e.from, to = e.to, dist = e.dist;
            if (d[to] > d[from] + dist) {
                d[to] = d[from] + dist;
                c[to] = c[from] + num[to];
                q.push((Hp){to, d[to]});
            } else if (d[to] == d[from] + dist) {
                c[to] = max(c[to], c[from] + num[to]);
            }
        }
    }
}

void dfs(ll star, ll dest, ll dist, ll &cnt) {//star起始点，dest目的地,dist目前走了多少,cnt结果
    if (dist > d[dest]) return;
    if (dist == d[dest] && star == dest) {
        cnt ++;
        return;
    }
    for (int i = 0; i < G[star].size(); i ++) {
        Edge &e = edge[G[star][i]];
        ll to = e.to, dist1 = e.dist;
        if (dist + dist1 == d[to]) {
            dfs(to, dest, d[to], cnt);
        }
    }
}

int main() {
    int n, m, star, dest;
    scanf("%d%d%d%d",&n,&m,&star,&dest);
    for (int i = 0; i < n; i ++) scanf("%lld",&num[i]);
    for (int i = 0; i < m; i ++) {
        ll from, to, dist; scanf("%lld%lld%lld",&from,&to,&dist);
        AddEdge(from, to, dist);
        AddEdge(to, from, dist);
    }
    Dij(star, n);
    ll cnt = 0;
    dfs(star, dest, 0, cnt);
    printf("%lld %lld\n",cnt,c[dest]);
    return 0;
}