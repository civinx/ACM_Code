//
//  main.cpp
//  Problem : Vote
//
//  Created by czf on 15/10/28.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 101 + 5;
int state[maxn];
int main() {
    int n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i ++) {
            cin >> state[i];
        }
        sort(state,state+n);
        int cnt = 0;
        for (int i = 0; i < n/2+1; i++) {
            cnt += state[i]/2 + 1;
        }
        cout << cnt << '\n';
    }
    return 0;
}
