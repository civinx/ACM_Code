//
//  main.cpp
//  Problem : Online Judge
//
//  Created by czf on 16/5/20.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5000+10;
bool ans1[maxn], ans2[maxn];

bool check(int n) {
    for (int i = 1; i <= n; i ++)
        if (ans1[i] != ans2[i]) return false;
    return true;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        memset(ans1, 0, sizeof(ans1));
        memset(ans2, 0, sizeof(ans2));
        string a, b, temp, res;
        int cnta = 0, cntb = 0;
        while (getline(cin, temp)) {
            if (temp == "START") {
                while (getline(cin, temp) && temp != "END"){
                    res += temp;
                    cnta ++;
                    if (!temp.size()) ans1[cnta] = 1;
                }
                a = res; res.clear();
                break;
            }
        }
        while (getline(cin, temp)) {
            if (temp == "START") {
                while (getline(cin, temp) && temp != "END") {
                    res += temp;
                    cntb ++;
                    if (!temp.size()) ans2[cntb] = 1;
                }
                b = res; res.clear();
                break;
            }
        }
        string x, y;
        int len1 = (int)a.size(), len2 = (int)b.size();
        for (int i = 0; i < len1; i ++)
            if (a[i] != ' ' && a[i] != '\t' && a[i] != '\n') x += a[i];
        for (int i = 0; i < len2; i ++)
            if (b[i] != ' ' && b[i] != '\t' && b[i] != '\n') y += b[i];
        if (a == b && cnta == cntb && check(cnta)) cout << "Accepted" << '\n';
        else if (x == y) cout << "Presentation Error" << '\n';
        else cout << "Wrong Answer" << '\n';
    }
    return 0;
}

