#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1000 + 10;
ll f[N<<2][3], c[N], w[N];

int main() {
    std::ios::sync_with_stdio(false);
    int t, kase = 0; cin >> t;
    while (t--) {
        memset(f, 0, sizeof(f));
        int m, n; cin >> m >> n;
        for (int i = 1; i <= m; i ++) cin >> c[i] >> w[i];
        cout << "Case #" << ++kase << ": ";
        if (m == 1) {
            cout << w[1] << '\n';
            continue;
        }
        for (int i = 1; i <= m; i ++) c[i] *= 2; n *= 2;
        for (int i = 1; i <= m; i ++) {
            for (int j = n; j >= c[i]/2; j --) {
                for (int k = 0; k <= 2; k ++) {
                    if (k != 0) f[j][k] = max(f[j][k], f[j-c[i]/2][k-1]+w[i]);
                    if (j >= c[i]) f[j][k] = max(f[j][k], f[j-c[i]][k]+w[i]);
                }
            }
        }
        cout << f[n][2] << '\n';
    }
    return 0;
}
