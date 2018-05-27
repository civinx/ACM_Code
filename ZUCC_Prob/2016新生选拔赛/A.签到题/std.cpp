#include <iostream>
#include <string>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string s; int n;
        cin >> s >> n;
        for (int i = 0; i < n; i ++) {
            cout << s << " " << "dalao!" << endl;
        }
    }
    return 0;
}
