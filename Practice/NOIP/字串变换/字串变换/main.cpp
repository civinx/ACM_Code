//
//  main.cpp
//  字串变换
//
//  Created by czf on 2017/1/25.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>
using namespace std;

const int maxn = 20;
string s1[maxn], s2[maxn], a, b;
int n;

struct P {
    string s;
    int cnt;
    P (string s, int cnt) : s(s), cnt(cnt) {};
};
void work() {
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    queue<P> q;
    q.push((P){a, 0});
    while (!q.empty()) {
        P cur = q.front(); q.pop();
        if (cur.s == b) {
            cout << cur.cnt << '\n';
            return;
        }
        if (cur.cnt >= 10) {
            continue;
        }
        for (int i = 0; i < n; i ++) {
            int pos = 0, x;
            while ((x = (int)cur.s.find(s1[i], pos)) != -1) {
                string s = cur.s;
                s.replace(x, s1[i].size(), s2[i]);
                if (s == b) {
                    cout << cur.cnt + 1 << '\n';
                    return;
                }
                q.push((P){s, cur.cnt+1});
                pos = x+1;
            }
        }
    }
    cout << "NO ANSWER!" << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> a >> b;
    while (cin >> s1[n] >> s2[n]) n ++;
    work();
    return 0;
}
