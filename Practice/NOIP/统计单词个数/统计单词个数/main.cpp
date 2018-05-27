//
//  main.cpp
//  统计单词个数
//
//  Created by czf on 2017/1/25.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 222;
string word[10];


int a[maxn][maxn], dp[maxn][50];
bool vis[maxn];

void count(int n, const string &s) {
    //枚举区间
    for (int i = 0; i < s.size(); i ++) {
        for (int j = i; j < s.size(); j ++) {
            memset(vis, 0, sizeof(vis));
            //枚举起点
            for (int st = i; st <= j; st ++) {
                if (vis[st]) continue;
                //一旦发现一个单词可行就break, 一个起点只能放一个单词
                for (int k = 0; k < n; k ++) {
//                    cout << s.substr(st, word[k].size()) << " " <<  word[k] << endl;
                    if (s.substr(st, word[k].size()) == word[k] && word[k].size() <= j - st + 1) {
                        a[i][j] ++;
                        vis[st] = 1;
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        string s;
        int t, K; cin >> t >> K;
        for (int i = 0; i < t; i ++) {
            string temp; cin >> temp;
            s += temp;
        }
        int n; cin >> n;
        for (int i = 0; i < n; i ++) {
            cin >> word[i];
        }
        count(n, s);
        
//        for (int i = 0; i < n; i ++) {
//            dp[i][0] = a[0][i];
//        }
//        for (int k = 1; k <= K; k ++) {
//            for (int i = 0; i < s.size(); i ++) {
//                for (int j = max(0, k-2); j < i; j ++) {
//                    dp[i][k] = max(dp[i][k], dp[j][k-1] + a[j+1][i]);
//                }
//            }
//        }
        
        for (int k = 1; k <= K; k ++) {
            for (int i = 0; i < s.size(); i ++) {
                for (int j = k-1; j <= i; j ++) {
                    dp[i][k] = max(dp[i][k], j ? dp[j-1][k-1] + a[j][i] : a[j][i]);
                }
            }
        }
        cout << dp[s.size()-1][K] << '\n';
    }
    return 0;
}
