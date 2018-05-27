//
//  main.cpp
//  Candies
//
//  Created by czf on 16/7/11.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
const int N = 50000 + 100;
double res[N];

int main () {
    res[1] = 1, res[2] = 0.5;
    for (int i = 3; i < N; i ++) {
        double n = i-1;
        res[i] = res[(int)n] * (2.0*n-1) * (2.0*n) * (0.25) / (n*n);
    }
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        cout << setiosflags(ios::fixed);
        cout << setprecision(5) << 1-res[x] << '\n';
    }
    return 0;
}
