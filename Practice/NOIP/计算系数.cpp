//
// Created by CZF on 2017/2/16.
//

//
// Created by CZF on 2017/2/16.
//

#include <iostream>
using namespace std;
typedef long long LL;

const LL MOD = 10007;
LL f[1111][1111];

int main() {
    LL a, b, k, n, m; cin >> a >> b >> k >> n >> m;
    f[1][0] = b, f[1][1] = a;
    for (int i = 2; i <= k; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (j) f[i][j] = (f[i][j] + f[i-1][j-1] * a % MOD) % MOD;
            if (i - j) f[i][j] = (f[i][j] + f[i-1][j] * b % MOD) % MOD;
        }
    }
    cout << f[k][n] << '\n';
    return 0;
}