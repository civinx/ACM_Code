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

const int maxn = 130000;
vector<int> res;
int a[maxn];
map<int, int> mp;

void init() {
    res.clear();
    mp.clear();
}
int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        if (n == 0) {
            printf("0\n");
            continue;
        }
        init();
        for (int i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
            if (mp.count(a[i]) == 0) {
                mp[a[i]] = 1;
            } else {
                mp[a[i]] ++;
            }
            
        }
        sort(a, a+n);
        for (int i = 0; i < n; i ++) {
            if (mp[a[i]] != 0) {
                mp[a[i]] --;
                for (int j = 0; j < res.size(); j ++) {
                    int sum = res[j] + a[i];
                    mp[sum] --;
                }
                res.push_back(a[i]);
            }
        }
        printf("%d\n",(int)res.size());
        for (int i = 0; i < res.size(); i ++) {
            printf("%d%c",res[i],i==res.size()-1?'\n':' ');
        }
    }
    return 0;
}