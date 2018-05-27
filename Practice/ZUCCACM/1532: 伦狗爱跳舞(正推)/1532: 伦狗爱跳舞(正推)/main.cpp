//
//  main.cpp
//  1532: 伦狗爱跳舞(正推)
//
//  Created by czf on 16/5/20.
//  Copyright © 2016年 czf. All rights reserved.
//

//
//  main.cpp
//  1532: 伦狗爱跳舞
//
//  Created by czf on 16/5/19.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 10;
const int inf = 0xfffffff;
int dp[5][5][maxn], e[5][5], a[maxn], n; //dp[i][j][k],跳完k次时 左脚在i，右脚在j，所需的最小值

void Init() {
    for (int i = 1; i <= 4; i ++) e[0][i] = e[i][0] = 2;
    for (int i = 0; i <= 4; i ++) e[i][i] = 1;
    e[1][2] = e[2][1] = e[2][3] = e[3][2] = e[3][4] = e[4][3] = e[1][4] = e[4][1] = 3;
    e[1][3] = e[3][1] = e[2][4] = e[4][2] = 4;
}

int main() {
    Init();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (cin >> n) {
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;
        int res = inf;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        for (int k = 0; k < n; k ++) {
            for (int i = 0; i <= 4; i ++) {
                for (int j = 0; j <= 4; j ++) {
                    if (dp[i][j][k] != -1) {
                        int next = a[k+1];
                        //                        printf("\n");
                        //                        printf("下一个位置是%d\n",next);
                        //                        printf("dp[%d][%d][%d] = %d推出\n",i,j,k, dp[i][j][k]);
                        dp[next][j][k+1] = (dp[next][j][k+1] == -1 ? dp[i][j][k] + e[i][next] : min(dp[next][j][k+1], dp[i][j][k] + e[i][next]));
                        //                        printf("dp[%d][%d][%d] = %d\n",next, j, k+1, dp[next][j][k+1]);
                        dp[i][next][k+1] = (dp[i][next][k+1] == -1 ? dp[i][j][k] + e[j][next] : min(dp[i][next][k+1], dp[i][j][k] + e[j][next]));
                        //                        printf("dp[%d][%d][%d] = %d\n", i, next, k+1, dp[i][next][k+1]);
                        if (k == n-1) res = min(res, min(dp[next][j][k+1], dp[i][next][k+1]));
                    }
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}


