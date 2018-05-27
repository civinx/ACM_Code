//
//  main.cpp
//  1163: 时间压缩射线枪
//
//  Created by czf on 15/11/6.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
const int rem = 1000000007;
const unsigned long long day = 86400;
int main() {
    int n;
    while (scanf("%d",&n) == 1) {
        unsigned long long x;
        x = day * n;
        int res = x % rem;
        printf("%d\n",res);
    }
}
