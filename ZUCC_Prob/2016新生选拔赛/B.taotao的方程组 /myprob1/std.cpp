#include <cstdio>

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        int a, b; scanf("%d%d",&a,&b);
        printf("Case #%d: %d\n",++kase,a+b);
    }
    return 0;
}
