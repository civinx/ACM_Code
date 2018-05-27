//
//  main.c
//  1012: 加法
//
//  Created by czf on 15/10/18.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        char a;
        int x,last;
        int sum = 0;
        while ((a = getchar()) != '=') {
            if (a >= '0' && a <= '9') {
                ungetc(a, stdin);
                scanf("%d",&x);
                sum += x;
            }
        }
        scanf("%d",&last);
        if (last == sum) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
