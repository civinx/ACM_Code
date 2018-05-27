//
//  main.cpp
//  1107. Social Clusters (30)
//
//  Created by czf on 2016/12/8.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 100;

vector<int> G[maxn];
int root[maxn], num[maxn];

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

int main() {
    int n; scanf("%d",&n);
    for (int i = 1; i <= n; i ++) root[i] = i, num[i] = 1;
    for (int i = 1; i <= n; i ++) {
        int k; scanf("%d: ",&k);
        for (int j = 0; j < k; j ++) {
            int x; scanf("%d",&x);
            G[x].push_back(i);
        }
    }
    for (int i = 1; i <= 1000; i ++) {
        if (G[i].size() > 0) {
            int x = G[i][0];
            x = find(x);
            //            printf("x = %d\n",x);
            for (int j = 1; j < G[i].size(); j ++) {
                int y = G[i][j];
                //                printf("y = %d\n",y);
                y = find(y);
                if (x != y) {
                    root[y] = x;
                    num[x] += num[y];
                }
            }
        }
    }
    int cnt = 0;
    vector<int> res;
    for (int i = 1; i <= n; i ++) {
        if (root[i] == i) {
            cnt ++;
            res.push_back(num[i]);
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n",cnt);
    for (int i = (int)res.size()-1; i >= 0; i --) {
        printf("%d%c",res[i],i==0?'\n':' ');
    }
    return 0;
}
