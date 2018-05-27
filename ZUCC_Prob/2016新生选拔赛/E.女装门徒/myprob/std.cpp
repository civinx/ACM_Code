#include <cstdio>
#include <cstring>
const int MAXN = 1000;

struct Triple {
    int a, b, c;
};

bool ok[MAXN];
Triple has[MAXN], need[MAXN], lim[MAXN];

bool check(int n) {
    for (int i = 0; i < n; i ++) if (!ok[i])
        return false;
    return true;
}

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        int n; scanf("%d",&n);
        int suma, sumb, sumc; scanf("%d%d%d",&suma,&sumb,&sumc);
        for (int i = 0; i < n; i ++) {
            scanf("%d%d%d%d%d%d",&has[i].a, &has[i].b, &has[i].c, &lim[i].a, &lim[i].b, &lim[i].c);
            need[i].a = lim[i].a - has[i].a;
            need[i].b = lim[i].b - has[i].b;
            need[i].c = lim[i].c - has[i].c;
        }
        memset(ok, 0, sizeof(ok));
        for (int i = 0; i < n; i ++) {
            bool flag = false;
            for (int j = 0; j < n; j ++) {
                if (!ok[j] && need[j].a <= suma && need[j].b <= sumb && need[j].c <= sumc) {
                    flag = ok[j] = true;
                    suma += has[j].a;
                    sumb += has[j].b;
                    sumc += has[j].c;
                }
            }
            if (!flag) break;
        }
        printf("Case #%d: ",++kase);
        if (check(n)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
