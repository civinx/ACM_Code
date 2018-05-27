#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


void f1(){
    std::ios::sync_with_stdio(false);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t; cin >> t; getchar();
    char x;
    while (t--) {
        for (string s; cin >> s; cout << " ") {
            reverse(s.begin(), s.end());
            cout << s;
            if ( (x=cin.get()) != ' ') break;
        }
        cout << endl;
    }
    return 0;
}