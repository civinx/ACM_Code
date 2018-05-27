//
//  main.cpp
//  5920 Ugly Problem (贪心 找最大回文数)
//
//  Created by czf on 2016/10/22.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2000;

string res[MAXN];
int cnt = 0;

void find(string &s) {
    string ret(s.size(), '9');
    //    cout << ret << '\n';
    for (int i = 0; i < (s.size()+1) / 2; i ++) {
        int j = s.size() - 1 - i;
        if (ret[i] > s[i]) ret[i] = ret[j] = s[i];
    }
    bool flag = 1;
    for (int i = 0; i < s.size(); i ++) {
        if (ret[i] > s[i]) { flag = 0; break; }
    }
    if (!flag) {
        for (int i = (s.size()+1) / 2; i >= 0 ; i --) {
            if (ret[i] != '0') {
                ret[i] = ret[s.size()-1-i] = (ret[i] - 1);
                flag = 1;
                break;
            }
        }
    }
    res[cnt++] = ret[0] != '0' ? ret : string(s.size()-1, '9');
    //    cout << res[cnt-1] << '\n';
    string temp = res[cnt-1];
    
    int c = 0;
    reverse(s.begin(), s.end());
    reverse(temp.begin(), temp.end());
    int i;
    for (i = 0; i < s.size() && i < temp.size(); i ++) {
        int cur = s[i] - '0';
        cur = cur - (temp[i] - '0') - c; c = 0;
        if (cur < 0) cur += 10, c = 1;
        s[i] = cur + '0';
    }
    if (c) s[i] --;
    reverse(s.begin(), s.end());
    while (s[0] == '0') s = s.substr(1);
    //    cout << s << '\n';
}

int main() {
    int T, kase = 0; cin >> T;
    while (T--) {
        string s; cin >> s;
        cnt = 0;
        while (s.size()) find(s);
        cout << "Case #" << ++kase << ":\n";
        cout << cnt << '\n';
        for (int i = 0; i < cnt; i ++) cout << res[i] << '\n';
    }
    return 0;
}
