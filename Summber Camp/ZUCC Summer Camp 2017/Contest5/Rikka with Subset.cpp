#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef long long LL;

const int maxm = 20000 + 100;

LL sum[maxm];
LL b[maxm];

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        memset(sum, 0, sizeof(sum));
        LL n, m; scanf("%lld%lld",&n,&m);
        for (int i = 0; i <= m; i ++) {
            scanf("%lld",&b[i]);
        }
        vector<LL> res;
        for (LL i = 1; i <= m; i ++) {
            if (b[i] == 0) continue;
            
            for (LL j = 0; j < b[i]; j ++) { // 对于每个个体 最多50次
                LL num = i;
                res.push_back(num);
                for (int k = 0; k+num <= m; k ++) {
                    if (sum[k] == 0) continue;
                    b[num+k] -= sum[k];
                }
                for (LL k = m-num; k >= 0; k --) {
                    if (sum[k] == 0) continue;
                    sum[k+num] += sum[k];
                }
                sum[num] ++;
            }
        }
        for (int i = 0; i < res.size(); i ++) {
            printf("%lld%c",res[i],i==res.size()-1?'\n':' ');
        }
    }
    return 0;
}