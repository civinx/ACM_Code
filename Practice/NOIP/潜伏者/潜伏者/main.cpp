//
//  main.cpp
//  潜伏者
//
//  Created by czf on 2017/2/7.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 30;
const int maxm = 111;

int a[maxn], b[maxn];
char s1[maxm], s2[maxm], s[maxm];

int main() {
    scanf("%s%s%s",s1,s2,s);
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
    int len = (int)strlen(s1);
    bool flag = true;
    for (int i = 0; i < len; i ++) {
        int u = s1[i] - 'A', v = s2[i] - 'A';
        if (a[u] != -1 && a[u] != v) {
            flag = false;
            break;
        }
        if (b[v] != -1 && b[v] != u) {
            flag = false;
            break;
        }
        a[u] = v;
        b[v] = u;
    }
    if (flag) {
        for (int i = 0; i < 26; i ++) {
            if (a[i] == -1) {
                flag = false;
                break;
            }
        }
    }
    if (!flag) printf("Failed\n");
    else {
        len = (int)strlen(s);
        for (int i = 0; i < len; i ++) {
            printf("%c",'A'+a[s[i]-'A']);
        }
        printf("\n");
    }
    return 0;
}
