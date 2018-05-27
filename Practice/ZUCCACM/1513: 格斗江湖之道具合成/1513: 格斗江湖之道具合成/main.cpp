//
//  main.cpp
//  1513: 格斗江湖之道具合成
//
//  Created by czf on 15/10/23.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
int main() {
    int t;
    int kase = 0;
    scanf("%d",&t);
    while (t--) {
        int n, m, k, cnt = 0;
        scanf("%d%d%d",&n,&m,&k);
        int flag = 0;
        if (m == k) {
            printf("Case #%d: %d\n",++kase,n);
            flag = 1;
        }
        for (int level = m; level < k; level ++) {
            if (level == k-1 && n >= 3){
                cnt = n/3;
            }
            n /= 3;
            if (n < 3) break;
        }
        if (!flag){
            printf("Case #%d: %d\n",++kase,cnt);
        }
    }
    return 0;
}
