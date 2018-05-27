//
//  main.cpp
//  进制转换
//
//  Created by czf on 2017/1/22.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 10;
const char s[25] = "0123456789ABCDEFGHIJK";
char a[maxn];

int main() {
    int n, r, cnt = 0; scanf("%d%d",&n,&r);
    printf("%d=",n);
    while (n) {
        int x = n % r;
        n /= r;
        if (x < 0) {
            x -= r;
            n ++;
        }
        a[cnt++] = s[x];
    }
    for (int i = cnt-1; i >= 0; i --) printf("%c",a[i]);
    printf("(base%d)\n",r);
    return 0;
}

