//
//  main.cpp
//  Problem : Max Sum Plus Plus
//
//  Created by czf on 16/5/17.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 10;
const ll inf = 0xffffffff;

ll dp[maxn], p[maxn], a[maxn];
//dp为滚动数组，代表当前组数前j个数的最大值，且必须以a[j]结尾
//p[j]保存上一组前j个数中的最大结果
//a[i]储存数字

int main() {
    int n, m;
    ll maxres = 0;
    while (~scanf("%d%d",&m,&n)) {
        memset(dp, 0, sizeof(dp));
        memset(p, 0, sizeof(p)); p[0] = 0;
        for (int i = 1; i <= n; i ++) scanf("%lld",&a[i]);
        for (int i = 1; i <= m; i ++) { //分i组
            maxres = -inf;
            for (int j = i; j <= n; j ++) { //第j个数
                dp[j] = max(dp[j-1] + a[j], p[j-1] + a[j]);//p[j]的旧值用好了。第二步
                p[j-1] = maxres;//把之前放在临时变量里的结果放进去
                maxres = max(maxres, dp[j]);//其实p[j]已经算好，但是下一轮任然要用到p[j]的旧值，所以先存起来。第一步
            }
        }
        printf("%lld\n",maxres);
    }
    return 0;
}
