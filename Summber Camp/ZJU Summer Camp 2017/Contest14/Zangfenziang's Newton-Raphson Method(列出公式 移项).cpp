#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long LL;

map<LL, LL> mp;

const LL MAX = 1e15;

int main() {
    LL n, k;
    while (scanf("%lld%lld",&n,&k) == 2) {
        LL sum = 0; mp.clear();
        mp[0] = 1;
        LL res = 0;
        for (int i = 0; i < n; i ++) {
            LL x; scanf("%lld",&x);
            sum += x;
            if (k == 1) {
                if (mp.count(sum-1))
                    res += mp[sum-1];
            } else if (k == -1) {
                if (mp.count(sum-1)) res += mp[sum-1];
                if (mp.count(sum+1)) res += mp[sum+1];
            } else {
                for (LL j = 1; j < MAX; j *= k) {
                    if (mp.count(sum - j)) res += mp[sum - j];
                }
            }
            if (!mp.count(sum)) mp[sum] = 1;
            else mp[sum] ++;
        }
        printf("%lld\n",res);
    }
    return 0;
}

