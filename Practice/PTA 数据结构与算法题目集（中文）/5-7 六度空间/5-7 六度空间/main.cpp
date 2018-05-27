//
//  main.cpp
//  5-7 六度空间
//
//  Created by czf on 16/2/13.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 10000 + 5;
vector<int> LINE[maxn];
bool vis[maxn];

void BFS(int x, int n){
    queue<int> q;
    q.push(x);
    memset(vis, 0, sizeof(vis));
    vis[x] = 1;
    int last = x, cnt = 1, level = 0, tail = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < LINE[v].size(); i ++) {
            if (!vis[LINE[v][i]]){
                q.push(LINE[v][i]);
                vis[LINE[v][i]] = 1;
                tail = LINE[v][i];
                cnt ++;
            }
        }
        if (last == v){
            last = tail;
            level ++;
        }
        if (level == 6){
            break;
        }
    }
    printf("%d: %.2f%%\n",x,cnt*100.0/n);
}
int main(){
    int n, m; scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i ++) {
        int a, b;
        scanf("%d%d",&a,&b);
        LINE[a].push_back(b);
        LINE[b].push_back(a);
    }
    for (int i = 1; i <= n; i ++) {
        BFS(i,n);
    }
    return 0;
}