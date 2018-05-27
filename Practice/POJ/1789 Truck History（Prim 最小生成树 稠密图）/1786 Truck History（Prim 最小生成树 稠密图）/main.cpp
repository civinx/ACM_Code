//
//  main.cpp
//  1786 Truck History（Prim 最小生成树 稠密图）
//
//  Created by czf on 16/4/24.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2000 + 100;
string s[maxn];
int d[maxn];
int edge[maxn][maxn];
int n;
//bool done[maxn];

struct P {
    int dist, num;
    bool operator >(const P &rhs) const {
        return dist > rhs.dist;
    }
};

int solve(const string &a, const string &b) {
    int ret = 0;
    for (int i = 0; i < 7; i ++)
        if (a[i] != b[i]) ret ++;
    return ret;
}

int main() {
    while (scanf("%d",&n) && n) {
        priority_queue<P, vector<P>, greater<P> > q;
        for (int i = 0; i < n; i ++) cin >> s[i];
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                edge[i][j] = solve(s[i], s[j]); //建立边
            }
        }
        for (int i = 1; i < n; i ++) d[i] = edge[0][i], q.push((P){d[i], i}); //初始化
        d[0] = 0;
        int res = 0;
        //        memset(done, 0, sizeof(done));
        while (!q.empty()) {
            P cur = q.top(); q.pop(); //拿出当前离树距离最小的点
            if (cur.dist != d[cur.num]) continue; //若不相等，说明这是一个虽然被更新，但还在队列中的旧点
            //            if (done[cur.num]) continue;
            //            done[cur.num] = 1;
            res += d[cur.num];
            d[cur.num] = 0; //归入树中
            for (int i = 0; i < n; i ++) { //遍历与该点相邻的每一个点
                if (d[i]) { //如果不在树中，等于0的话代表是树的一部分
                    if (edge[cur.num][i] < d[i]) //取那个点与老树，和新树（刚加入的点）更近的距离
                        d[i] = edge[cur.num][i], q.push((P){d[i], i});
                }
            }
        }
        printf("The highest possible quality is 1/%d.\n",res);
    }
    return 0;
}

