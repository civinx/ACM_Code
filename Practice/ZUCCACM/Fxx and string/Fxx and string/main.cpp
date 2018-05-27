//
//  main.cpp
//  Fxx and string
//
//  Created by czf on 2017/3/16.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 1e4 + 10;
char s[maxn];

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%s",s+1); int len = (int)strlen(s+1); int cnt = 0;
        for (int i = 1; i <= len / 4; i ++) {
            if (s[i] == 'y') {
                for (int j = 2; i * j * j <= len; j ++) {
                    if (s[i * j] == 'r' && s[i * j * j] == 'x') cnt ++;
                }
            }
            if (s[i] == 'x') {
                for (int j = 2; i * j * j <= len; j ++) {
                    if (s[i * j] == 'r' && s[i * j * j] == 'y') cnt ++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
