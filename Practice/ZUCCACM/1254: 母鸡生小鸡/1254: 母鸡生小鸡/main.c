//
//  main.c
//  1254: 母鸡生小鸡
//
//  Created by czf on 15/11/11.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define maxn 51
int main() {
    int  a[maxn] = {0,1,1,1,2};
    int ans = 1;
    for (int i = 5; i <= 50; i ++) {
        ans += a[i-3] - a[i-4];
        a[i] = a[i-1] + ans;
    }
    int n;
    while (scanf("%d",&n) == 1) {
        printf("%d\n",a[n]);
    }
    return 0;
}
