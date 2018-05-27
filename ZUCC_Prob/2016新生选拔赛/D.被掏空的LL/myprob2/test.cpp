#include <cstdio>

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        int n, m, k;
        scanf("%d%d%d",&n,&m,&k);
        bool flag = false;
        if (k == 0) {
            if (m > 0) {
                flag = 1;
            }
        } else {
            if (m / k >= n) {
                flag = 1;
            }
        }
        printf("Case #%d: ",++kase);
        if (flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
