//
//  main.cpp
//  1519: 溜冰的翔饼
//
//  Created by czf on 15/10/23.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
const int maxn = 1000 + 10;

struct p{
    double x;
    double y;
};

p kid[maxn];
p xiangbin;

int Isboom (p a,p b){
    int ret = 0;
    double distance;
    distance = sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
    if (distance <= 5) ret = 1;
    return ret;
}

int main() {
    int t;
    scanf("%d",&t);
    int kase = 0;
    while (t--) {
        int n;
        scanf("%d",&n);
        scanf("%lf%lf",&xiangbin.x,&xiangbin.y);
        for (int i = 0; i < n; i ++){
            scanf("%lf%lf",&kid[i].x,&kid[i].y);
        }
        int flag = 0;
        for (int i = 0; i < n; i ++) {
            if (Isboom(xiangbin, kid[i])) {
                flag = 1;
                break;
            }
        }
        if (flag)printf("Case #%d: Yes\n",++kase);
        else printf("Case #%d: No\n",++kase);
    }
    return 0;
}
