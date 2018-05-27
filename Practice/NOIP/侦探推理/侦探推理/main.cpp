//
//  main.cpp
//  侦探推理
//
//  Created by czf on 2017/1/26.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int maxn = 22;
map<string, int> mp;

const string Day[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
string Name[maxn];

int n, m, k, G[maxn][maxn], today[maxn];

void init(int k) {
    memset(today, -1, sizeof(today));
    memset(G, -1, sizeof(G));
    int pos = 0;
    for (int i = 0; i < k; i ++) {
        string s;
        while (s == "") getline(cin, s);
        string name = s.substr(0, s.find(":"));
        s = s.substr(s.find(":")+2);
        int id = mp[name];
        if (s == "I am guilty.") {
            G[id][id] = 1;
        } else if (s == "I am not guilty.") {
            G[id][id] = 0;
        } else if ((pos = (int)s.find(" is guilty.")) != -1) {
            string name1 = s.substr(0, pos);
            int id1 = mp[name1];
            G[id][id1] = 1;
        } else if ((pos = (int)s.find(" is not guilty.")) != -1) {
            string name1 = s.substr(0, pos);
            int id1 = mp[name1];
            G[id][id1] = 0;
        } else if ((pos = (int)s.find("Today is")) != -1) {
            string str = "Today is ";
            string day = s.substr(str.size(), s.size() - str.size() - 1);
            bool flag = 0;
            int i;
            for (i = 0; i < 7; i ++) {
                if (day == Day[i]) {
                    flag = 1;
                    break;
                }
            }
            if (flag) today[id] = i;
        }
    }
    
}

// 0不确定 1假话 2真话 3自相矛盾
int check(int x, int id, int day) {
    int T = 0, F = 0; // T代表说过真话 F代表说过假话
    if (today[x] != -1) {
        if (today[x] == day) T = 1;
        else F = 1;
    }
    for (int i = 0; i < n; i ++) {
        if (G[x][i] == -1) continue;
        if ((G[x][i] == 1 && i == id) || (G[x][i] == 0 && i != id)) T = 1;
        else F = 1;
    }
    if (!T && !F) return 0;
    if (!T && F) return 1;
    if (T && !F) return 2;
    return 3;
}

bool solve(int id, int day) {
    int t = 0, f = 0, u = 0;
    for (int i = 0; i < n; i ++) {
        int ret = check(i, id, day);
        if (ret == 3) return false;
        if (ret == 1) f ++;
        else if (ret == 2) t ++;
        else u ++;
        if (f > m) return false;
    }
    return u >= m - f;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i ++) {
        string s; while (s == "") getline(cin, s);
        mp[s] = i;
        Name[i] = s;
    }
    init(k);
    int id = -1, cnt = 0;
    for (int i = 0; i < n; i ++) {
        bool flag = 0;
        for (int j = 0; j < 7; j ++) {
            if (solve(i, j)) {
                id = i;
                flag = 1;
                break;
            }
        }
        if (flag) cnt ++;
    }
    if (cnt == 0) {
        cout << "Impossible" << '\n';
    } else if (cnt == 1) {
        cout << Name[id] << '\n';
    } else {
        cout << "Cannot Determine" << '\n';
    }
    return 0;
}
