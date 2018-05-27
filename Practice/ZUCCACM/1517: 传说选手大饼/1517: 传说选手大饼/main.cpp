//
//  main.cpp
//  1517: 传说选手大饼
//
//  Created by czf on 15/10/23.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int Iswho (string s){
    int ret;
    if (s[0] == 'B' || s[1] == 'B') {
        ret = 1;
        if (s[0] == 'K') {
            ret = 2;
        }
    }
    else ret = 0;
    return ret;
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        string x;
        int a[8];
        int cnt = 7;
        for (int i = 0; i < 8; i ++) {
            cin >> x;
            a[i] = Iswho(x);
        }
        int flag = 0;
        for (int i = 0; i < 6; i ++) {
            if (a[i] == 0){
                if (a[i+2] == 2) {flag = 1; break;}
            }
            else if (a[i] == 2){
                if (a[i+2] == 0) {flag = 1; break;}
                else if (a[i+2] == 1 || a[i+2] == 2) {cnt--;}
            }
            else if (a[i] == 1){
                if (a[i+2] == 1 || a[i+2] == 2) {cnt--;}
            }
        }
        if (flag) printf("1\n");
        else printf("%d\n",cnt);
    }
    return 0;
}
