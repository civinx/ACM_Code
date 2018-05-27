//
//  main.c
//   背单词
//
//  Created by czf on 15/10/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);
    int a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    while (t--) {
        int n,m,d;
        scanf("%d%d%d",&n,&m,&d);
        int day;
        if (m < 12) {
            day = a[m] - d + 1;
        }
        else day = 14 - d;
        for (int i = m + 1; i < 12; i ++) {
            day += a[i];
        }
        if (m != 12) day += 13;
        int word = 0;
        for (int i = 0; i < day; i++) {
            word += n;
            n ++;
        }
        printf("%d\n",word);
    }
    return 0;
}
