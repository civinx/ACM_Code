#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn = 200000 + 100;
//const int maxn = 100;
const int inf = 0x3f3f3f3f;

bool isp[maxn];
int f[maxn];

void init() {
    for (int i = 0; i < maxn; i ++) isp[i] = 1;
    for (int i = 0; i < maxn; i ++) f[i] = inf;
    isp[1] = 0;
    for (LL i = 2; i < maxn; i ++) { if (isp[i])
        for (LL j = i * i; j < maxn; j += i) {
            isp[j] = 0;
        }
    }
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    f[4] = 4;
    f[5] = 5;
    for (int i = 6; i < maxn; i ++) {
        if (isp[i]) {
            f[i] = f[i-1] + 1;
        } else {
            if (i == 6) {
                int x = 0;
                x --;
            }
            int mx = sqrt(i);
            for (int j = 2; j <= mx; j ++) {
                if (i % j == 0) {
                    f[i] = min(f[i], f[j] + f[i/j]);
                }
            }
        }
        for (int j = 1; j <= 5; j ++) {
            f[i] = min(f[i], f[i-1] + j);
        }
    }
}

int main() {
    init();
    int x;
    while (scanf("%d",&x) == 1) {
        printf("%d\n",f[x]);
    }
    return 0;
}