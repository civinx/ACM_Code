//
//  main.cpp
//  1114. Family Property (25)
//
//  Created by czf on 2016/12/7.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 100;

int root[MAXN], sets[MAXN], area[MAXN], num[MAXN], mp[MAXN];

struct P {
    int id, size;
    double AVG_sets, AVG_area;
    bool operator < (const P &rhs) const {
        if (AVG_area == rhs.AVG_area)
            return id < rhs.id;
        return AVG_area > rhs.AVG_area;
    }
};

vector<int> G[MAXN];
vector<int> v;
vector<P> res;

void init() {
    for (int i = 0; i < MAXN; i ++) root[i] = i, num[i] = 1;
    memset(sets, 0, sizeof(sets));
    memset(area, 0, sizeof(area));
    memset(mp, 0, sizeof(mp));
}

int find(int x) {
    return x == root[x] ? x : root[x] = find(root[x]);
}

int main() {
    init();
    int n; scanf("%d",&n);
    for (int i = 0; i < n; i ++) {
        int id, fa, ma, k; scanf("%d%d%d%d",&id,&fa,&ma,&k);
        if (fa != -1) {
            G[id].push_back(fa);
            if (!mp[fa]) v.push_back(fa), mp[fa] = 1;
        }
        if (ma != -1) {
            G[id].push_back(ma);
            if (!mp[ma]) v.push_back(ma), mp[ma] = 1;
        }
        if (!mp[id]) v.push_back(id), mp[id] = 1;
        for (int i = 0; i < k; i ++) {
            int x; scanf("%d",&x);
            G[id].push_back(x);
            if (!mp[x]) v.push_back(x), mp[x] = 1;
        }
        int s, a; scanf("%d%d",&s,&a);
        sets[id] = s, area[id] = a;
    }
    for (int i = 0; i < v.size(); i ++) {
        int x = v[i];
        for (int j = 0; j < G[x].size(); j ++) {
            int y = G[x][j];
            int x1 = find(x), y1 = find(y);
            if (x1 != y1) {
                if (x1 > y1) swap(x1, y1);
                root[y1] = x1;
                num[x1] += num[y1];
                sets[x1] += sets[y1];
                area[x1] += area[y1];
            }
        }
    }
    for (int i = 0; i < v.size(); i ++) {
        int id = v[i];
        //        printf("id = %d, root[%d] = %d\n", id, id, root[id]);
        if (id == root[id]) {
            res.push_back((P){id, num[id], sets[id] * 1.0 / num[id], area[id] * 1.0 / num[id]});
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n",(int)res.size());
    for (int i = 0; i < res.size(); i ++) {
        printf("%04d %d %.3f %.3f\n",res[i].id, res[i].size, res[i].AVG_sets, res[i].AVG_area);
    }
    return 0;
}
