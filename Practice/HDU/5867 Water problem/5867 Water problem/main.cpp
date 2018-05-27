//
//  main.cpp
//  5867 Water problem
//
//  Created by czf on 16/8/25.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 100;
int E[maxn];

int solve(int x) {
    if (x <= 20) return E[x];
    if (x % 100 == 0) return E[x];
    if (x < 100) {
        return E[x/10*10]+E[x%10];
    }
    if (x % 100 <= 20) return E[x/100*100] + 3 + E[x%100];
    return E[x/100*100] + 3 + E[x%100/10*10] + E[x%10];
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    E[0]=0;
    E[1]=3;     E[11]=6;
    E[2]=3;     E[12]=6;                E[200]=10;
    E[3]=5;     E[13]=8;    E[30]=6;    E[300]=12;
    E[4]=4;     E[14]=8;    E[40]=5;    E[400]=11;
    E[5]=4;     E[15]=7;    E[50]=5;    E[500]=11;
    E[6]=3;     E[16]=7;    E[60]=5;    E[600]=10;
    E[7]=5;     E[17]=9;    E[70]=7;    E[700]=12;
    E[8]=5;     E[18]=8;    E[80]=6;    E[800]=12;
    E[9]=4;     E[19]=8;    E[90]=6;    E[900]=11;
    E[10]=3;    E[20]=6;    E[100]=10;  E[1000]=11;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int res = 0;
        for (int i = 1; i <= n; i ++) res += solve(i);
        cout << res << '\n';
    }
    return 0;
}