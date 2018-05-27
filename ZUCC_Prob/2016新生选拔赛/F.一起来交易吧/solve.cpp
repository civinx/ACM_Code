#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL T; cin >> T;
    cout << T << endl;
    while (T--) {
        LL n; cin >> n;
        cout << n << endl;
        for (int i = 0; i < n; i ++) {
            LL a, b; cin >> a >> b;
            if (a > b) swap(a, b);
            cout << a << " " << b << endl;
        }
    }
    return 0;
}
