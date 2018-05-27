//
//  main.cpp
//  5-9 旅游规划
//
//  Created by czf on 16/2/26.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const int INF = 0xfffffff;
const int maxn = 500 + 5;

struct Dijkstra {
    struct Edge {
        int from, to, dist, cost;
        Edge(int u, int v, int d, int c) : from(u), to(v), dist(d), cost(c) {}
    };
    
    struct HeapNode {
        int d, c, u;
        bool operator < (const HeapNode rhs) const{
            return d > rhs.d;
        }
    };
    int n, m;
    vector<Edge> edges; //边集
    vector<int> G[maxn]; //每个点所连的边的编号集
    int d[maxn];
    int c[maxn];
    bool done[maxn];
    
    void init(int n) {
        this->n = n;
        for(int i = 0; i < n; i ++) G[i].clear();
        edges.clear();
    }
    
    void AddEdge(int from, int to, int dist, int cost) {
        edges.push_back(Edge(from, to, dist, cost));
        m = edges.size();
        G[from].push_back(m-1);
        edges.push_back(Edge(to, from, dist, cost));
        m = edges.size();
        G[to].push_back(m-1);
    }
    
    void dijkstra(int s) {
        priority_queue<HeapNode> q;
        for(int i = 0; i < n; i ++) { d[i] = INF; c[i] = INF; done[i] = 0; }
        d[s] = 0; c[s] = 0;
        q.push((HeapNode){0, 0, s});
        while(!q.empty()){
            HeapNode x = q.top(); q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = 1;
            for(int i = 0; i < G[u].size(); i ++){
                Edge &e = edges[G[u][i]]; //e即当前扫描的边
//                if (done[e.to]) continue;
                if (d[e.to] > d[u] + e.dist) {
                    d[e.to] = d[u] + e.dist;
                    c[e.to] = c[u] + e.cost;
                    q.push((HeapNode){d[e.to], c[e.to], e.to});
                } else if (d[e.to] == d[u] + e.dist && c[u] + e.cost < c[e.to]) {
                    c[e.to] = c[u] + e.cost;
                    q.push((HeapNode){d[e.to], c[e.to], e.to});
                }
            }
        }
    }
};

int main() {
    int N, M, S, D;
    string s = "12345";
    scanf("%d%d%d%d",&N,&M,&S,&D);
    Dijkstra solve;
    solve.init(N);
    for(int i = 0; i < M; i ++){
        int from, to, dist, cost;
        scanf("%d%d%d%d",&from,&to,&dist,&cost);
        solve.AddEdge(from, to, dist, cost);
    }
    solve.dijkstra(S);
    printf("%d %d\n",solve.d[D],solve.c[D]);
    return 0;
}