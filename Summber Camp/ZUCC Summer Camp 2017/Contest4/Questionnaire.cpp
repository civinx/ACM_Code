#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        int g1 = 0, g2 = 0;
        for (int i = 0; i < n ; i ++) {
            int x; scanf("%d",&x);
            if (x % 2) g1 ++;
            else g2 ++;
        }
        if (g1 > g2) {
            printf("2 1\n");
        } else {
            printf("2 0\n");
        }
    }
    return 0;
}