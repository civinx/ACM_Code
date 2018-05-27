//
//  main.cpp
//  4433 locker (dp)
//
//  Created by czf on 2016/10/25.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;
const int INF = 0x3f3f3f3f;

int dp[MAXN][10][10];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    string s1, s2;
    while (cin >> s1 >> s2) {
        memset(dp, INF, sizeof(dp));
        int n = (int)s1.size();
        dp[0][0][0] = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < 10; j ++) {
                for (int k = 0; k < 10; k ++) {
                    int up = (s2[i] - s1[i] - j + 20) % 10;
                    for (int x = 0; x <= up; x ++) {
                        for (int y = 0; y <= x; y ++) {
                            dp[i+1][(k+x)%10][y] = min(dp[i+1][(k+x)%10][y], dp[i][j][k] + up);
                        }
                    }
                    int down = (10 - up) % 10;
                    //                    cout << 10 -up << " " << down << endl;;
                    for (int x = 0; x <= down; x ++) {
                        for (int y = 0; y <= x; y ++) {
                            //                            cout << (10-y)%10 << " " << 10-y << endl;
                            dp[i+1][(k-x+10)%10][(10-y)%10] = min(dp[i+1][(k-x+10)%10][(10-y)%10], dp[i][j][k] + down);
                        }
                    }
                }
            }
        }
        cout << dp[n][0][0] << '\n';
    }
    return 0;
}
