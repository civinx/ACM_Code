//
//  main.cpp
//  1516: 画个圈圈诅咒你
//
//  Created by czf on 15/10/23.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100 + 5;

int root[maxn];
int record[2][maxn];

int find_root (int x){
    return x == root[x] ? x : find_root(root[x]);
}

int Isok(int x,int y){
    int ret = 1;
    if (find_root(x) == find_root(y)) {
        ret = 0;
    }
    if (root[x] != x) ret = 0;
    return ret;
}

int main() {
    int t;
    int kase = 0;
    scanf("%d",&t);
    while (t--) {
        int n,m;
        int sign = 1;
        int cnt = 0;
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i ++) root[i] = i;
        for (int i = 0; i < m; i ++) {
            int flag = 0;
            int x,y;
            scanf("%d%d",&x,&y);
            
            for (int i = 0; i < cnt; i++) {
                if (record[0][i] == x && record[1][i] == y) {flag = 1;break;}
            }
            if (flag) continue;
            record[0][cnt] = x;
            record[1][cnt] = y;
            cnt ++;
            
            if (Isok(x, y)){
                x[root] = y;
            }
            else sign = 0;
        }
        if (sign) printf("Case #%d: Yes\n",++kase);
        else printf("Case #%d: No\n",++kase);
    }
    return 0;
}
