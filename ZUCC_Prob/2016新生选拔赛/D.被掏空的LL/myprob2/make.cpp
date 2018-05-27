#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 1e9;
const int MAXM = 10;
int n, m, k;

bool check() {
    if (n >= 1 && k >= 0 && m >= k) {
        return true;
    }
    return false;
}

int main() {
    srand (time(NULL));
    int T = 1000; cout << T << endl;
    
    while (T--) {
        int mod = (T >= 980 ? MAXN : MAXM);
        n = rand() % mod; //人数
        m = rand() % mod; //物资
        k = rand() % mod; //需要的
        if (!check()) {
            T ++;
            continue;
        }
        if (T == 2) {
            k = 0, n = 1, m = 0;
        }
        if (T == 1) {
            k = 1, n = 1, m = 0;
        }
        if (T == 0) {
            k = 1, n = 1, m = 1;
        }
        cout << n << " " << m << " " << k << endl;
    }
    return 0;
}
