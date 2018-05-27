//
//  main.cpp
//  金明的预算方案
//
//  Created by czf on 2017/2/1.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 66;
const int maxm = 33333;

vector<int> G[maxn];
vector<int> key;
struct P { int val, rank; };

P a[maxn];

int dp[maxm];

int main() {
    //m钱  n物品个数
    int m, n; cin >> m >> n;
    for (int i = 1; i <= n; i ++) {
        int flag; cin >> a[i].val >> a[i].rank >> flag;
        flag == 0 ? key.push_back(i) : G[flag].push_back(i);
    }
    
    //枚举主件
    for (int idx = 0; idx < key.size(); idx ++) {
        int i = key[idx];
        //枚举所花的钱
        for (int j = m; j >= a[i].val; j --) {
            //枚举物品所属物拿或不拿的状态, k是一个状态
            for (int k = 0; k < (1 << G[i].size()); k ++) {
                int cost = a[i].val;
                int res = a[i].val * a[i].rank;
                for (int l = 0; l < G[i].size(); l ++) {
                    if ((1<<l) & k) {
                        cost += a[G[i][l]].val;
                        res += a[G[i][l]].rank * a[G[i][l]].val;
                    }
                }
                if (j >= cost) {
                    dp[j] = max(dp[j], dp[j-cost] + res);
                }
            }
        }
    }
    
    cout << dp[m] << '\n';
    return 0;
}
