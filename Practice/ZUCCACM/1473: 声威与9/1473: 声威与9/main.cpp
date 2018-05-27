//
//  main.cpp
//  1473: 声威与9
//
//  Created by czf on 15/11/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100 + 5;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a[maxn] ,ans[maxn] = {0}, cnt = 0 ,n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0 && a[i] == 9) { cnt ++; ans[i] = 1;}
            else if (!ans[i-1] && a[i] == 9) { cnt ++; ans[i] = 1;}
        }
        cout << cnt << endl;
    }
    return 0;
}
