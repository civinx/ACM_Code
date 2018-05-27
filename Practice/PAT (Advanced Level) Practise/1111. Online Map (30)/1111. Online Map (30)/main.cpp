//
//  main.cpp
//  1111. Online Map (30)
//
//  Created by czf on 2016/12/7.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500 + 100;
const int INF = 0x7fffffff;

struct Edge {
    int from, to, dist, tim;
};

int d[MAXN][2]; // d[i][0],fir; d[i][1],sec
int pre[MAXN];
int s, t, n, m;
bool vis[MAXN];
vector<int> G[MAXN];
vector<Edge> edges;


void AddEdge(int from, int to, int dist, int tim) {
    edges.push_back((Edge){from, to, dist, tim});
    int m = (int)edges.size() - 1;
    G[from].push_back(m);
}

struct P {
    int id, d1, d2;
    bool operator > (const P & rhs) const {
        if (d1 == rhs.d1)
            return d2 > rhs.d2;
        return d1 > rhs.d1;
    }
};

vector<int> dijkstra(int op) { //0:dist; 1:time
    //    memset(d, INF, sizeof(d));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 2; j ++) {
            d[i][j] = INF;
        }
    }
    memset(pre, -1, sizeof(pre));
    d[s][0] = d[s][1] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push(P{s, 0, 0});
    while (!q.empty()) {
        P cur = q.top(); q.pop();
        int from = cur.id;
        if (vis[from]) continue;
        vis[from] = 1;
        for (int i = 0; i < G[from].size(); i ++) {
            Edge &e = edges[G[from][i]];
            int to = e.to, d1, d2;
            if (op == 0) d1 = e.dist, d2 = e.tim;
            else d1 = e.tim, d2 = 1;
            if (cur.d1 + d1 <= d[to][0]) {
                if (cur.d1 + d1 < d[to][0]) {
                    d[to][0] = cur.d1 + d1; //交汇点最少...
                    d[to][1] = cur.d2 + d2;
                    q.push((P){to, d[to][0], d[to][1]});
                    pre[to] = from;
                } else if (cur.d2 + d2 < d[to][1]) {
                    d[to][1] = cur.d2 + d2;
                    q.push((P){to, d[to][0], d[to][1]});
                    pre[to] = from;
                }
            }
        }
    }
    vector<int> ret;
    int t1 = t;
    while (t1 != -1) {
        ret.push_back(t1);
        t1 = pre[t1];
    }
    return ret;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i ++) {
        int from, to, op, dist, tim; scanf("%d%d%d%d%d",&from,&to,&op,&dist,&tim);
        AddEdge(from, to, dist, tim);
        if (!op) AddEdge(to, from, dist, tim);
    }
    scanf("%d%d",&s,&t);
    vector<int> Dis = dijkstra(0); int dis = d[t][0];
    vector<int> Time = dijkstra(1); int tim = d[t][0];
    bool flag = 1;
    if (Dis.size() == Time.size()) {
        for (int i = 0; i < Dis.size(); i ++) {
            if (Dis[i] != Time[i]) {
                flag = 0;
                break;
            }
        }
    } else flag = 0;
    if (s == t) {
        printf("Distance = 0; Time = 0: %d -> %d\n", s, t);
    } else if (flag) {
        printf("Distance = %d; Time = %d: ",dis, tim);
        for (int i = (int)Dis.size()-1; i >= 0; i --) {
            if (i != (int)Dis.size()-1) printf(" -> ");
            printf("%d",Dis[i]);
        }
    } else {
        printf("Distance = %d: ",dis);
        for (int i = (int)Dis.size()-1; i >= 0; i --) {
            if (i != (int)Dis.size()-1) printf(" -> ");
            printf("%d",Dis[i]);
        }
        printf("\n");
        printf("Time = %d: ",tim);
        for (int i = (int)Time.size()-1; i >= 0; i --) {
            if (i != (int)Time.size()-1) printf(" -> ");
            printf("%d",Time[i]);
        }
    }
    printf("\n");
    return 0;
}
