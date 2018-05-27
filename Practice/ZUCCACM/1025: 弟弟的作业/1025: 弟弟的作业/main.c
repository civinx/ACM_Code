//
//  main.c
//  1025: 弟弟的作业
//
//  Created by czf on 15/10/18.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int x,last;
    int cnt = 0;
    char t;
    while (scanf("%d",&x) != EOF) {
        int sum = 0;
        sum += x;
        t = getchar();
        scanf("%d",&x);
        if (t == '+') sum += x;
        else sum -= x;
        getchar();
        t = getchar();
        if (t >= '0' && t <= '9') {
            ungetc(t, stdin);
            scanf("%d",&last);
            if (sum == last) cnt ++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
