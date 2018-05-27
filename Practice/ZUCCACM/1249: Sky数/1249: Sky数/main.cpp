//
//  main.cpp
//  1249: Sky数
//
//  Created by czf on 15/11/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int sum(int x, int num){
    int ret = 0;
    while (x) {
        ret += x%num;
        x /= num;
    }
    return ret;
}
int main() {
    int x;
    while (scanf("%d",&x) == 1 && x) {
        if (x > 9999 || x < 1000){
            printf("%d is not a Sky Number.\n",x);
            continue;
        }
        if ((sum(x, 10) == sum(x, 12)) && (sum(x, 12) == sum(x, 16))) {
            printf("%d is a Sky Number.\n",x);
        }
        else printf("%d is not a Sky Number.\n",x);
    }
    return 0;
}
