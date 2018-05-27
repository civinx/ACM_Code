//
//  main.cpp
//  1094 Sorting It All Out（拓扑排序）
//
//  Created by czf on 16/5/15.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 30;
vector<int> G[maxn];
vector<int> res;
int in[maxn];

void Init() {
//    for (auto i : G) i.clear();
    for (int i = 0; i < maxn; i ++) G[i].clear();
    memset(in, 0, sizeof(in));
}

int Topo(int n) {
    int temp[maxn];
    int flag = 1;
    for (int i = 0; i < n; i ++) temp[i] = in[i];
    for (int i = 0; i < n; i ++) {
        int ans = 0, step = 0;
        for (int i = 0; i < n; i ++) if (!temp[i]) ans ++, step = i;
        if (!ans) return -1;
        if (ans > 1) flag = 0;
        res.push_back(step);
        temp[step] = -1;
        for (int i = 0; i < G[step].size(); i ++) {
            int to = G[step][i];
            temp[to] --;
        }
    }
    return flag;
}

int main() {
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m && (n || m)) {
        Init();
        int flag = 0;
        for (int i = 1; i <= m; i ++) {
            string s; cin >> s;
            if (flag) continue;
            int x = s[0] - 'A', y = s[2] - 'A';
            G[x].push_back(y); in[y] ++;
            flag = Topo(n);
            if (flag == -1) {
                cout << "Inconsistency found after " << i << " relations." << '\n';
                continue;
            }
            if (flag == 1) {
                cout << "Sorted sequence determined after " << i <<  " relations: ";
//                for (auto i : res) cout << char('A' + i);
                for (int i = 0; i < res.size(); i ++) cout << (char)('A'+res[i]);
                cout << ".\n";
                continue;
            }
            res.clear();
        }
        if (!flag) cout << "Sorted sequence cannot be determined." << '\n';
    }
    return 0;
}
