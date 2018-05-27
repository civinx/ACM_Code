#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))

using namespace std;
typedef long long LL;

bool check(LL a, LL b) {
    if (a == 0) {
        return false;
    }
    if (a == 1e9) {
        return b != 0;
    }
    return b != 1e9 - a && (a > 1e9 || a < -1e9);
}

int main() {
    LL a, b;
    while (scanf("%lld%lld",&a,&b) == 2) {
        if (check(a, b)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}