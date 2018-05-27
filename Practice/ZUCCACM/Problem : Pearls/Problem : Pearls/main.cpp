//
//  main.cpp
//  Problem : Pearls
//
//  Created by czf on 16/5/18.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200;
const int inf = 0xfffffff;
int a[maxn], p[maxn], sum[maxn], dp[maxn];
/*我们购买的珍珠个数一定
 *可以用高品质的珍珠代替低品质珍珠
 *珍珠的价格是随着品质等级递增的
 *那么决策就在于是否要用一种高品质珍珠来代替低品质，且这种替换是连续的，反证：第i类珍珠可以用i+2类珍珠代替，那么显然用i+1类会更便宜
 *所以当购买i类珍珠时，它要么管自己独立购买，要么代替的一个连续的[j,i]区间类的珍珠一起买，枚举j = 1至i。等于i时也就是管自己独立购买
 *用一个sum[i]代表前i类珍珠需要购买数量的和 dp[i] = max((sum[i] - sum[j] + 10) * 价格 + dp[j])，j∈[0,i-1]，当j == i-1时，
 *也就是独立购买,j == 0时，就是用第i种珍珠代替之前的所有珍珠，当然 dp[0] = 0
 */

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i ++) cin >> a[i] >> p[i];
        for (int i = 0; i <= n; i ++) sum[i] = (i == 0 ? 0 : sum[i-1] + a[i]);
        for (int i = 0; i <= n; i ++) dp[i] = (i == 0 ? 0 : inf);
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j < n; j ++) {
                dp[i] = min(dp[i], (sum[i] - sum[j] + 10) * p[i] + dp[j]);
            }
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
