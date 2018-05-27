#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define pb push_back
#define MS(x, y) memset(x, y, sizeof(x))
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
#define AS(x, L, R) assert((L) <= x && x <= (R))
using namespace std;
typedef long long LL;
// const int MOD = 10000;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i ++) {
            int x; cin >> x;
            sum1 += x;
            // sum1 %= MOD;
        }
        for (int i = 0; i < n; i ++) {
            int x; cin >> x;
            sum2 += x;
            // sum2 %= MOD;
        }
        cout << sum1 * sum2  << endl;
    }
    return 0;
}

