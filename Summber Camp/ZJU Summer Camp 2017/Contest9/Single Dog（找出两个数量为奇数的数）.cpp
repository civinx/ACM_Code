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
using namespace std;
typedef long long LL;

void solve1(int n) {
    int res = 0;
    for (int i = 0; i < n; i ++) {
        int x; scanf("%d",&x);
        res ^= x;
    }
    printf("%d\n",res);
}

void solve2(int n) {
    int xor_res = 0;
    int g[32];
    memset(g, 0, sizeof(g));
    for (int i = 0; i < n; i ++) {
        int x; scanf("%d",&x);
        for (int j = 0; j < 32; j ++) {
            if (x & (1 << j)) {
                g[j] ^= x;
            }
        }
        xor_res ^= x;
    }
    int k = 0;
    while (((1 << k) & xor_res) == 0) k ++;
    int g1 = xor_res ^ g[k];
    int g2 = xor_res ^ g1;
    if (g1 > g2) swap(g1, g2);
    printf("%d %d\n",g1,g2);
    
}
int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n, k; scanf("%d%d",&n,&k);
        if (k == 1) solve1(n);
        else solve2(n);
    }
    return 0;
}