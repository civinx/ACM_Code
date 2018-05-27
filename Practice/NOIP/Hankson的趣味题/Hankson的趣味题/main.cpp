//
//  main.cpp
//  Hankson的趣味题
//
//  Created by czf on 2017/2/8.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

struct P {
    int val;
    vector<int> num, exp;
};

void init(P &a) {
    int end = (int)sqrt(a.val), x = 2;
    while (x <= end) {
        int cnt = 0;
        while (a.val % x == 0) {
            cnt ++;
            a.val /= x;
        }
        if(cnt) {
            a.num.push_back(x);
            a.exp.push_back(cnt);
        }
        x ++;
    }
    if (a.val != 1) {
        a.num.push_back(a.val);
        a.exp.push_back(1);
    }
}



int main() {
    int T; cin >> T;
    while (T--) {
        P a0, a1, b0, b1; cin >> a0.val >> a1.val >> b0.val >> b1.val;
        vector<int> mi, mx;
        init(b1);
        bool flag = 1;
        for (int i = 0; i < b1.num.size(); i ++) {
            int x = b1.num[i], cnt_b0 = 0, cnt_a0 = 0, cnt_a1 = 0;
            while (b0.val % x == 0) cnt_b0 ++, b0.val /= x;
            while (a0.val % x == 0) cnt_a0 ++, a0.val /= x;
            while (a1.val % x == 0) cnt_a1 ++, a1.val /= x;
            if (cnt_b0 > b1.exp[i] || cnt_a0 < cnt_a1) {
                flag = 0;
                break;
            }
            if (b1.exp[i] < cnt_a1) {
                flag = 0;
                break;
            }
            b0.exp.push_back(cnt_b0);
            a0.exp.push_back(cnt_a0);
            a1.exp.push_back(cnt_a1);
        }
        int res = 1;
        if (flag) {
            for (int i = 0; i < b1.num.size(); i ++) {
                if (b1.exp[i] == b0.exp[i] && a0.exp[i] == a1.exp[i]) {
                    mi.push_back(a1.exp[i]);
                    mx.push_back(b1.exp[i]);
                } else if (b1.exp[i] == b0.exp[i]) {
                    mi.push_back(a1.exp[i]);
                    mx.push_back(a1.exp[i]);
                } else if (a1.exp[i] == a0.exp[i]) {
                    mi.push_back(b1.exp[i]);
                    mx.push_back(b1.exp[i]);
                } else {
                    mi.push_back(b1.exp[i]);
                    mx.push_back(a1.exp[i]);
                    if (a1.exp[i] != b1.exp[i]) {
                        flag = 0;
                        break;
                    }
                }
            }
            for (int i = 0; i < b1.num.size(); i ++) res *= mx[i] - mi[i] + 1;
        }
        if (flag) cout << res << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}

