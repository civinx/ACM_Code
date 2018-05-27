//
//  main.cpp
//  Problem : [JSOI2007]建筑抢修
//
//  Created by czf on 2016/11/5.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long LL;
const int MAXN = 150000 + 100;

struct P {
    LL t1, t2;
    bool operator < (const P &rhs) const {
        return t1 < rhs.t1;
    }
};

bool cmp(const P &lhs, const P &rhs) {
    if (lhs.t2 == rhs.t2) return lhs.t1 < rhs.t1;
    return lhs.t2 < rhs.t2;
}

P a[MAXN];

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        for (int i = 0; i < n; i ++) {
            scanf("%lld%lld",&a[i].t1,&a[i].t2);
        }
        sort(a, a+n, cmp);
        priority_queue<P> q;
        LL sum = 0, cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (a[i].t1 + sum <= a[i].t2) {
                sum += a[i].t1;
                cnt ++;
                q.push(a[i]);
            } else if(!q.empty()) {
                if (a[i].t1 < q.top().t1) {
                    sum -= q.top().t1;
                    sum += a[i].t1;
                    q.pop();
                    q.push(a[i]);
                }
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
