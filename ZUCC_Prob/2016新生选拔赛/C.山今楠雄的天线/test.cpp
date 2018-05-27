#include <stdio.h>

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x%y);
}

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        int n, p, q; scanf("%d%d%d",&n,&p,&q);
        int lcm = (p * q / gcd(p, q));
        printf("Case #%d: %d\n",++kase, n - (n/p + n/q - 2*(n/lcm)));
    }
    return 0;
}
