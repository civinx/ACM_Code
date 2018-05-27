#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long LL;

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        LL x; scanf("%lld",&x);
        if (x == 1) {
            printf("1\n");
        } else {
            printf("%lld\n",x/2);
        }
    }
    return 0;
}
