#include <cstdio>
typedef long long ll;

ll solve(ll a, ll b, ll mod) {
    ll ret = 0;
    for(; b; b >>= 1){
        if (b & 1) ret = (ret + a) % mod;
        a = (a + a) % mod;
    }
    return ret;
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int n;
        ll res, x, m;
        scanf("%d%lld",&n,&m);
        scanf("%lld",&res);
        for(int i = 1; i < n; i ++){
            scanf("%lld",&x);
            res = solve(res, x, m);
        }
        printf("%lld\n",res % m);
    }
    return 0;
}