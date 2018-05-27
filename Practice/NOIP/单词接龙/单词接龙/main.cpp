//
//  main.cpp
//  单词接龙
//
//  Created by czf on 2017/1/22.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
const int maxn = 22;

string s[maxn];
int a[maxn], res, n;

int cmp(string s1, string s2) {
    
    for (int i = s1.size()-1; i >= 0; i --) {
        if (s1[i] == s2[0]) {
            int j = 0;
            for (; j < s2.size(); j ++) {
                if (i+j >= s1.size() || s1[i+j] != s2[j]) break;
            }
            if (i + j < s1.size()) return -1;
            return j == s2.size() ? -1 : j;
        }
    }
    return -1;
}

void dfs(int sum, int id, int pos) {
    res = max(sum, res);
    for (int i = 0; i < n; i ++) {
//        if (i == id) continue;
        if (a[i] <= 0) continue;
        int x = cmp(s[id], s[i]);
        if (x == -1) continue;
        a[i] --;
        dfs(sum + s[i].size() - x, i, x);
        a[i] ++;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> s[i];
        a[i] = 2;
    }
    cin.get();
    char c; cin >> c;
    for (int i = 0; i < n; i ++) {
        if (s[i][0] == c) {
            a[i] --;
            dfs(s[i].size(), i, 0);
            a[i] ++;
        }
    }
    cout << res << '\n';
    return 0;
}
