//
//  main.cpp
//  Problem : 最长回文
//
//  Created by czf on 16/6/2.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110000 + 100;
//const int maxn = 10;
char str[maxn], temp[maxn<<1];
int Len[maxn<<1];

int init() {
    int len = (int)strlen(str);
    temp[0] = '@';
    for (int i = 1; i <= len * 2; i += 2) {
        temp[i] = '#';
        temp[i+1] = str[i/2];
    }
    temp[2*len+1] = '#';
    temp[2*len+2] = '$';
    temp[2*len+3] = '\0';
    return 2 * len + 1;
}

int main() {
    while (~scanf("%s",str)) {
        int len = init();
        int mx = 0, po = 0, res = 0;
        for (int i = 1; i <= len; i ++) {
            int j = 2 * po - i;
            if (i < mx) Len[i] = min(Len[j], mx - i);
            else Len[i] = 1;
            while (temp[i+Len[i]] == temp[i-Len[i]]) Len[i] ++;
            if (Len[i] + i > mx) {
                mx = Len[i] + i;
                po = i;
            }
            res = max(res, Len[i]);
        }
        printf("%d\n",res-1);
    }	
    return 0;
}

