//
//  main.cpp
//  1109. Group Photo (25)
//
//  Created by czf on 2016/12/8.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 100;

struct P {
    string name;
    int h;
    bool operator < (const P &rhs) const {
        if (h == rhs.h)
            return name < rhs.name;
        return h > rhs.h;
    }
};

P a[maxn];
string res[maxn];

int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i ++) {
        cin >> a[i].name >> a[i].h;
    }
    sort(a, a+n);
    int row = k, col = n / k;
    P *b = a;
    for (int i = 0; i < row; i ++) {
        int num = (i == 0 ? col + (n % col) : col);
        int m = num / 2;
        for (int j = 0; j < num; j ++) {
            int off = (j + 1) >> 1;
            if (j & 1) off = -off;
            res[m+off] = b[j].name;
        }
        b += num;
        for (int j = 0; j < num; j ++) {
            cout << res[j];
            j == num-1 ? (cout << endl) : (cout << " ");
        }
    }
    return 0;
}

//m    0
//m-1  1
//m+1  2
//m-2  3
//m+2  4
//m-3  5
//m+3  6
