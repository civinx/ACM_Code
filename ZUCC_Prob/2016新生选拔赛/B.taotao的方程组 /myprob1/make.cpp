#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;
typedef long long LL;
const int MIN = 0;
const int MAX = (1<<30)-1;
const int CASE = 1000; //组数

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(MIN,MAX);

int getrandom() {
    int ret = distribution(generator);
    return ret;
}

int main() {
    int T = CASE; cout << T << endl;
    while (T--) {
        int a = getrandom(), b = getrandom();
        cout << (a^b) << " " << ((a&b)<<1) << endl;
    }
    return 0;
}
