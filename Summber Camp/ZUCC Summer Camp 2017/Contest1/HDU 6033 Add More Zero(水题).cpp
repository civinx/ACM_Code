#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;

typedef long long LL;
int main() {
    int kase = 0;
    int x;
    while (scanf("%d",&x) == 1) {
        int res = x * log(2) / log(10);
        printf("Case #%d: %d\n",++kase, res);
    }
    return 0;
}
