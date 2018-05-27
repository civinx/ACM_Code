#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 2;
const int MAXM = 100;

bool check(int x1, int x2, int x3, int x4, int x5, int x6) {
    if (x1 >= x4 && x2 >= x5 && x3 >= x6) {
        return false;
    }
    return true;
}

int main() {
    srand (time(NULL));
    int T = 1000; cout << T << endl;
    for (int _ = 0; _ < T; _ ++) {
        int n = 0;
        if (_ < 500) {
            n = rand() % 4 + 1; // [1, 5)
        } else if (_ < 700) {
            n = rand() % 4 + 5; // [5, 10)
        } else if (_ < 900) {
            n = rand() % 90 + 10; // [10, 100)
        } else {
            n = rand() % 900 + 100; //[100, 1000)
        }
        if (_ >= 950) {
            n = rand() % 100 + 900;
        }
        if (_ >= 990) {
            n = 999;
        }
        cout << n << endl;
        int suma = rand() % MAXM;
        int sumb = rand() % MAXM;
        int sumc = rand() % MAXM;
        if (_ >= 600 && _ <= 995) {
            suma = rand() % MAXN;
            sumb = rand() % MAXN;
            sumc = rand() % MAXN;
        }
        cout << suma << " " << sumb << " " << sumc << endl;
        for (int i = 0; i < n; i ++) {
            int x1, x2, x3, x4, x5, x6;
            x1 = rand() % MAXM;
            x2 = rand() % MAXM;
            x3 = rand() % MAXM;
            x4 = rand() % MAXM;
            x5 = rand() % MAXM;
            x6 = rand() % MAXM;
            if (!check(x1, x2, x3, x4, x5, x6)) {
                i --;
                continue;
            }
            cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << " " << x6 << endl;
        }
    }
    return 0;
}
