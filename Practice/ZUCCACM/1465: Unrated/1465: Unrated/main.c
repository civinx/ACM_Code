//
//  main.c
//  1465: Unrated
//
//  Created by czf on 15/10/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            int x;
            scanf("%d",&x);
            if (x != 0) cnt ++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
