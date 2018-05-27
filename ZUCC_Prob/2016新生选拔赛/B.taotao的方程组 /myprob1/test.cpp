#include <cstdio>

int main() {
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        long long a, b; scanf("%lld%lld",&a,&b);
        printf("Case #%d: %lld\n",++kase, a+b);
    }
    return 0;
}
