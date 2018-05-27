//
//  main.cpp
//  1403: 只出现一次的数
//
//  Created by czf on 15/11/11.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main() {
    int n, res, x = 0;
    while (scanf("%d",&n) == 1) {
        for (int i = 0; i < n; i ++) {
            scanf("%d",&x);
            if (i)
                res ^= x;
            else
                res = x;
        }
        printf("%d\n",res);
    }
    return 0;
}
