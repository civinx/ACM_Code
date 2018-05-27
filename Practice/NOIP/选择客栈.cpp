//
// Created by CZF on 2017/2/13.
//
#include <cstdio>
const int maxn = 55;

int last[maxn], cnt[maxn], useful[maxn];

int main() {
    int n, k, p, pos = -1, res = 0; scanf("%d%d%d",&n,&k,&p);
    for (int i = 1; i <= n; i ++) {
        int color, price; scanf("%d%d",&color,&price);
        if (price <= p) pos = i;
        if (last[i] <= pos) useful[color] = cnt[color];
        last[x] = i;
        cnt[x] ++;
        res += useful[color];
        printf("i = %d\n",i);
    }
    printf("%d\n",res);
    return 0;
}
