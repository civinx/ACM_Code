//
//  main.cpp
//  5936 Difference 搜索 （搜索 剪枝）
//
//  Created by czf on 2016/11/21.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

LL fact[10][10], a[10], res, k, x; //a[]代表y的组成,a[i] = j表示i有j个。


void init() { //预处理次方
    for (int i = 0; i < 10; i ++) fact[i][0] = 1;
    for (int i = 0; i < 10; i ++) {
        for (int j = 1; j < 10; j ++) {
            fact[i][j] = fact[i][j-1] * i;
        }
    }
}

void dfs(int has, int pos) { //has表示接下来组成还能使用多少个数字，pos表示目前在枚举pos这个数字要用几次
    if (has == 0 || pos > 9) { //接下来没有数字可以用了，或者9个数字已经枚举完了
        LL sum = 0; //f(y, k)
        for (int i = 1; i < 10; i ++) {
            sum += fact[i][k] * a[i];
        }
        LL y = sum - x;
        if (y <= 0) return;
        LL b[10] = {0}; //算出来y值的组成
        while (y) {
            b[y%10] ++;
            y /= 10;
        }
        for (int i = 0; i < 10; i ++) { //判断枚举y的组成和算出来y的组成是否相同
            if (a[i] != b[i]) return;
        }
        res ++;
        return;
    }
    for (int i = 0; i <= has; i ++) { //枚举pos这个数字有几个
        a[pos] = i;
        dfs(has - i, pos + 1);
    }
}

int main() {
    init();
    int T, kase = 0; scanf("%d",&T);
    while (T--) {
        res = 0;
        memset(a, 0, sizeof(a));
        scanf("%lld%lld",&x,&k);
        dfs(10, 0);
        printf("Case #%d: %lld\n",++kase, res);
    }
    return 0;
}
