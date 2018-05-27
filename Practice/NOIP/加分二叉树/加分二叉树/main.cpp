//
//  main.cpp
//  加分二叉树
//
//  Created by czf on 2017/1/28.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
using namespace std;
typedef long long LL;

const int maxn = 33;

LL dp[maxn][maxn], a[maxn];
int root[maxn][maxn];

bool flag = 0;
void print(int L, int R) {
    if (L > R) return;
    if (!flag) flag = 1;
    else cout << " ";
    cout << root[L][R];
    print(L, root[L][R] - 1);
    print(root[L][R]+1, R);
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    
    for (int i = 1; i < maxn; i ++) {
        for (int j = 1; j < maxn; j ++) {
            dp[i][j] = (i == j ? a[i] : 1);
            root[i][j] = (i == j ? i : -1);
        }
    }
    
    //边界, 两个节点的二叉树
    for (int i = 1; i < n; i ++) {
        dp[i][i+1] = a[i] + a[i+1];
        root[i][i+1] = i;
    }
    
    for (int d = 1; d < n; d ++) {
        for (int l = 1; l + d <= n; l ++) {
            //注意此处边界, 不然会取到区间外面去, 所以要在之前处理好两个节点的二叉树
            for (int k = l+1; k < l + d; k ++) {
                if (dp[l][k-1] * dp[k+1][l+d] + a[k] > dp[l][l+d]) {
                    root[l][l+d] = k;
                    dp[l][l+d] = dp[l][k-1] * dp[k+1][l+d] + a[k];
                }
            }
        }
    }
    
    cout << dp[1][n] << '\n';
    print(1, n); cout << '\n';
    return 0;
}
