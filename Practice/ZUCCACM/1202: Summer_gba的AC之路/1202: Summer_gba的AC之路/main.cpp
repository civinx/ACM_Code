//
//  main.cpp
//  1202: Summer_gba的AC之路
//
//  Created by czf on 15/11/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
int main() {
    int n, a[maxn] = {0};
    while (scanf("%d",&n) == 1) {
        int sum = 0, temp = 0;
        for (int i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for (int i = 0; i < n; i ++) {
            temp = a[i] + temp;
            sum += temp;
        }
        printf("%d\n",sum);
    }
    return 0;
}
