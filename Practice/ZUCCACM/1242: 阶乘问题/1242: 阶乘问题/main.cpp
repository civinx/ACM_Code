//
//  main.cpp
//  1242: 阶乘问题
//
//  Created by czf on 15/11/6.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>

int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        int cnt = 0;
        while (n/5) {
            cnt += n/5;
            n /= 5;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
