//
//  main.c
//  1462: 翔饼涂饼
//
//  Created by czf on 15/10/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n, cnt = 0;
        scanf("%d",&n);
        while (n != 0) {
            n /= 2;
            cnt ++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
