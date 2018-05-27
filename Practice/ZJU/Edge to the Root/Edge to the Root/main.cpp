//
//  main.cpp
//  Edge to the Root
//
//  Created by czf on 2017/4/11.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 200000 + 100;
//const int maxn = 10;

typedef long long LL;

vector<int> G[maxn];

LL dep[maxn], size[maxn];
int nxt[maxn];


void dfs1(int fa, int x) {
    for (int i = 0; i < G[x].size(); i ++) {
        int v = G[x][i];
        if (v == fa) continue;
        dep[v] = dep[x] + 1;
        dfs1(x, v);
        size[x] += size[v] + 1;
    }
}

//sum1走捷径且直接往下走的点个数 sum2走捷径迂回去的点个数
LL sum1, sum2, sum, res;
void dfs(int fa, int x, int mid) {
    for (int i = 0; i < G[x].size(); i ++) {
        int v = G[x][i];
        if (v == fa) continue;
        LL t0 = sum, t1 = sum1, t2 = sum2, t3 = mid;
        if (dep[mid] < dep[x] - dep[mid] + 2) { //中点下移
            if (mid != x) {
                LL temp = size[mid] - size[nxt[mid]]; //因为中点下移导致增加的不影响的部分
                sum2 -= temp;
                mid = nxt[mid];
            } else {
                mid = v;
                sum2 -= size[x] - size[v];
            }
        }
        LL temp = size[x] - size[v]; //x下移导致增加的通过捷径走但要迂回去走的部分
        sum1 -= temp;
        sum2 += temp;
        if (dep[v] > 1) {
            sum -= sum1;
            sum += sum2;
        }
        
        res = min(res, sum);
        nxt[x] = v;
        dfs(x, v, mid);
        sum = t0; sum1 = t1; sum2 = t2; mid = t3;
    }
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        memset(size, 0, sizeof(size));
        memset(dep, 0, sizeof(dep));
        memset(nxt, 0, sizeof(nxt));
        int n; scanf("%d",&n);
        for (int i = 1; i < maxn; i ++) G[i].clear();
        for (int i = 0; i < n-1; i ++) {
            int u, v; scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dep[1] = 0;
        dfs1(0, 1);
        sum = 0;
        for (int i = 1; i <= n; i ++) sum += dep[i];
        res = sum;
        sum1 = size[1] + 1;
        sum2 = 0;
        dfs(0, 1, 1);
        printf("%lld\n",res);
    }
    return 0;
}





