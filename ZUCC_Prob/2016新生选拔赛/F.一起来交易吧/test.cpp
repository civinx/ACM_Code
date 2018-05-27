
// Created by Andor on 2016/11/8.


#include <iostream>
std::int64_t high[1000005];
std::int64_t low[1000005];
int main() {
    std::int64_t r;
    std::ios_base::sync_with_stdio(false);
    std::cin >> r;
    for (auto ri = 1; ri <= r; ++ri) {
        std::int64_t t;
        std::cin >> t;
        std::int64_t ans = 0;
        for (auto i = 1; i <= t; ++i) {
            std::int64_t p1, p2;
            std::cin >> p1 >> p2;
            if (p1 > p2)
                std::swap(p1, p2);
            low[i] = p1;
            high[i] = p2;
        }
        std::int64_t max = high[t];
        for (auto i = t - 1; i > 0; --i) {
            if (max > low[i])
                ans += max - low[i];
            max = std::max(max, high[i]);
        }
        std::cout<< "Case #" << ri << ": " << ans << '\n';
    }
    return 0;
}
//#include <cstdio>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//#include <string>
//#include <iostream>
//using namespace std;
//const int maxn = 1000000 + 100;
//typedef long long LL;
//
//LL mx[maxn], mi[maxn];
//
//int main() {
//    int T, kase = 0; scanf("%d",&T);
//    while (T--) {
//        int n; scanf("%d",&n);
//        for (int i = 0; i < n; i ++) {
//            scanf("%lld%lld",&mi[i],&mx[i]);
//            if (mi[i] > mx[i]) swap(mi[i], mx[i]);
//        }
//        LL ans = mx[n-1], sum = 0;
//        for (int i = n-2; i >= 0; i --) {
//            if (mx[i] > ans) {
//                if (mi[i] < ans)
//                    sum += ans - mi[i];
//                ans = mx[i];
//            } else {
//                sum += ans - mi[i];
//            }
//        }
//        printf("Case #%d: %lld\n",++kase,sum);
//    }
//    return 0;
//}
//
//
