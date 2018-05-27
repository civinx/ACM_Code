//
//  main.c
//  1568: 鱼妹的翔饼
//
//  Created by czf on 15/10/13.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define maxn 1010
char a[maxn];
int main() {
    int T;
    int b[26];
    scanf("%d",&T);
    while (T--) {
        memset(b, 0, sizeof(b));
        int cnt = 0;
        scanf("%s",a);
        for (int i = 0; a[i] != '\0'; i ++) {
            if (a[i] >= 'A' && a[i] <= 'Z') {
                b[a[i] - 'A'] = 1;
            }
            else{
                b[a[i] - 'a'] = 1;
            }
        }
        for (int i = 0; i < 26; i ++) {
            if (b[i]) cnt ++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
