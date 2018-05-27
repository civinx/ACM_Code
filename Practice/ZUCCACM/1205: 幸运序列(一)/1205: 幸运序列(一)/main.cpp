//
//  main.cpp
//  1205: 幸运序列(一)
//
//  Created by czf on 15/10/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 100000+5;
char a[maxn];
int  b[maxn] = {0};
int main() {
    int m, n, l, r, res;
    while (scanf("%d%d",&n,&m) != EOF) {
        scanf("%s",a);
        for (int i = 0; i < n; i++) {
            b[i+1] = b[i];
            if (a[i] == '7') {
                b[i+1] ++;
            }
        }
        for (int i = 0; i < m; i ++) {
            scanf("%d%d",&l,&r);
            res = b[r] - b[l];
            if (a[l-1] == '7') res ++;
            printf("%d\n",res);
        }
    }
    return 0;
}
