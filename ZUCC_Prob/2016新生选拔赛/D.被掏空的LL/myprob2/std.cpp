#include <cstdio>

bool check(int n, int m, int k) {
    if (k == 0) return true;
    if (k == 1) return m > 0;
    return (m-1) / (k-1) >= n;
}

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        int n, m, k; scanf("%d%d%d",&n,&m,&k);
        printf("Case #%d: ",++kase);
        if (check(n, m, k)) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
