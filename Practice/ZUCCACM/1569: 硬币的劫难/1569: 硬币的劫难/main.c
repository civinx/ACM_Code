//
//  main.c
//  1569: 硬币的劫难
//
//  Created by czf on 15/10/12.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int cnt = 0;
        int n,m;//n硬币数 m总额
        scanf("%d%d",&n,&m);
        for (int i = 0; i <= m/5; i ++) {//规律 每个五分数的所有可能硬币数不同
            int min = (m - i*5 + 1) / 2 + i; //五分等于i时需要最少的硬币数
            int max = (m - i*5) + i;//五分等于i时需要最多的硬币数
            if (n >= min && n <= max) cnt ++;//如果硬币数在那个范围内 肯定有一种可能
        }
        printf("%d\n",cnt);
    }
    return 0;
}
