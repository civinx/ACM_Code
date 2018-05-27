#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long LL;


int getCnt(LL a) {
    int ret = 0;
    while (a % 2 == 0) {
        ret ++;
        a /= 2;
    }
    return ret;
}

bool solve(LL a, LL b, LL c) {
    int g1 = getCnt(a);
    int g2 = getCnt(b);
    int g3 = getCnt(c);
    return g1 == g2 && g2 == g3;
}

int main() {
    LL a, b, c;
    while (scanf("%lld%lld%lld",&a,&b,&c) == 3) {
        bool flag = solve(a, b, c);
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

