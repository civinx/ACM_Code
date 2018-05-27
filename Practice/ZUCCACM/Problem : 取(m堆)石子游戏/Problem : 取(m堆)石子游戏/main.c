//
//  main.c
//  Problem : 取(m堆)石子游戏
//
//  Created by czf on 15/10/23.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define maxn 200010
int a[maxn];
int main() {
    int m;
    while (scanf("%d",&m) && m) {
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            scanf("%d",&a[i]);
            ans ^= a[i];
        }
        if (!ans) printf("No\n");
        else{
            printf("Yes\n");
            for (int i = 0; i < m; i ++) {
                int need = ans ^ a[i];
                if (need < a[i]) printf("%d %d\n",a[i],need);
            }
        }
    }
    return 0;
}
