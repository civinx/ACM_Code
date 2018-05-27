//
//  main.cpp
//  1466: 呆豪的5s
//
//  Created by czf on 15/10/25.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n,m;
    while (cin >> n >> m) {
        int cnt = 0;
        getchar();
        for (int i = 0; i < n*m; i ++){
            char x;
            cin >> x;
            if ((i+1)%m == 0) getchar();
            if (x == '0') cnt ++;
        }
        if (cnt > n*m/2) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}
