//
//  main.cpp
//  统计数字
//
//  Created by czf on 2017/2/3.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
typedef long long LL;
using namespace std;
const int maxn = 200000 + 100;

int a[maxn];

int main() {
    int n; scanf("%d",&n);
    for (int i = 0; i < n; i ++) scanf("%d",&a[i]);
    sort(a, a + n);
    int cnt = 1;
    for (int i = 0; i < n; i ++) {
        if (i != n-1 && a[i] == a[i+1]) {
            cnt ++;
        } else {
            printf("%d %d\n",a[i],cnt);
            cnt = 1;
        }
    }
    return 0;
}
