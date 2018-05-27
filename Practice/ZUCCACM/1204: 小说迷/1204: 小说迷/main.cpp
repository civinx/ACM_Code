//
//  main.cpp
//  1204: 小说迷
//
//  Created by czf on 15/10/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n ,m;
    while (cin >> n >> m) {
        int price;
        for (int i = 0; i < m; i ++) {
            cin >> price;
            if (n - price / 1000 * 3 < 0) continue;
            n -= price / 1000 * 3;
        }
        cout << n << '\n';
    }
    return 0;
}
