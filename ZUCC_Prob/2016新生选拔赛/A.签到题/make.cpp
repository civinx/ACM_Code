#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAXN = 9;

string s[10] = {"kkkwhswhsswhswhswhsswhswhswhsswhswhswhsswhswhswhsswhswhswhsswhswhswhsswhswhswxxx", "oyyf", "oooswhswhsswhswhswhsswhswhswhsswhswhwhsswhswhswhsswhswccchsswhswhswhsswhswhswhss", "lyh", "ll", "csj", "xjb", "xjz", "zyzyzyzyzy", "oooswhswhsswhswhswhsswhswhswhsswhswhswhsswhswhswhsswhswccchsswhswhswzzzwhsxwhswh"};
int main() {
    srand (time(NULL));
    int T = 10; cout << T << endl;
    while (T--) {
        int n = rand() % MAXN + 1;
        cout << s[T] << " " << n << endl;
    }
    return 0;
}
