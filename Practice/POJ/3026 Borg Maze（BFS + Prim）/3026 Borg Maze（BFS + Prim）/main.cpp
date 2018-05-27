//
//  main.cpp
//  3026 Borg Maze（BFS + Prim）
//
//  Created by czf on 16/4/25.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 200;
const int maxx = 20000;
const int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

struct P {
    int x, y;
    bool operator < (const P &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};

struct QP {
    int x, y, step;
};

struct Edge {
    int from, to, dist;
};

struct HP {
    int num, dist;
    bool operator > (const HP &rhs) const {
        return dist > rhs.dist;
    }
};

vector<Edge> edge;
vector<int> G[maxx];
int d[maxn];
char pic[maxn][maxn];
bool vis[maxn][maxn];
map<P, int> M;
map<int, P> M1;

bool check(const QP &p, const int &n, const int &m) {
    int x = p.x, y = p.y;
    if (x >= n || x < 0 || y >= m || y < 0) return 0;
    if (pic[x][y] == '#') return 0;
    if (vis[x][y]) return 0;
    return 1;
}

void AddEdge(int from, int to, int dist) {
    edge.push_back((Edge){from, to, dist});
    int m = (int)edge.size() - 1;
    G[from].push_back(m);
}

void bfs(const QP &star, const int &n, const int &m) { //find all distances from an "A" to other "A"
    memset(vis, 0, sizeof(vis));
    queue<QP> q;
    q.push(star); vis[star.x][star.y] = 1;
    while (!q.empty()) {
        QP cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, step = cur.step;
        if (pic[x][y] == 'A') {
            P u{star.x,star.y}, v{x,y};
            int from = M[u], to = M[v], dist = cur.step;
            AddEdge(from, to, dist);
        }
        for (int i = 0; i < 4; i ++) {
            QP next;
            next.x = x + dir[i][0];
            next.y = y + dir[i][1];
            next.step = step + 1;
            if (!check(next, n, m)) continue;
            vis[next.x][next.y] = 1;
            q.push(next);
        }
    }
}

int Prim(int n) {
    priority_queue<HP, vector<HP>, greater<HP> > q;
    for (int i = 0; i < G[0].size(); i ++) {
        Edge &e = edge[i];//???
        int to = e.to, dist = e.dist;
        d[to] = dist;
        q.push((HP){to,dist});
    }
    d[0] = 0;
    int ret = 0, cnt = 0;
    while (!q.empty() && cnt < n-1) {
        HP cur = q.top(); q.pop();
        if (cur.dist != d[cur.num] || !d[cur.num]) continue;
        cnt ++;
        ret += d[cur.num];
        d[cur.num] = 0;
        for (int i = 0; i < G[cur.num].size(); i ++) {
            Edge &e = edge[G[cur.num][i]];
            if (d[e.to] > e.dist) {
                d[e.to] = e.dist;
                q.push((HP){e.to, e.dist});
            }
        }
    }
    return ret;
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n, m; scanf("%d%d",&m,&n);
        string temp; getline(cin, temp);
        int cnt = 0; //cnt为A的个数
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                char c; scanf("%c",&c);
                pic[i][j] = c = (c == 'S' ? 'A' : c);
                if (c == 'A') { P p{i, j}; M[p] = cnt; M1[cnt++] = p; }
            }
            getline(cin,temp);
        }
        for (int i = 0; i < cnt; i ++) { //寻找任意两个A,并建立边
            P p = M1[i]; QP star{p.x,p.y};
            bfs(star,n,m);
        }
        int res = Prim(cnt);
        printf("%d\n",res);
        edge.clear();
        for (int i = 0; i < maxx; i ++) G[i].clear();
        M.clear();
        M1.clear();
    }
    return 0;
}
