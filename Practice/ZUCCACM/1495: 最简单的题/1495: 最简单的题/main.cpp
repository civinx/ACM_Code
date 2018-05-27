//
//  main.cpp
//  1495: 最简单的题
//
//  Created by czf on 15/11/5.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    cin.get();
    while (t--) {
        string s;
        cin >> s;
        int flag = 0;
        for (int i = 0; i < s.length(); i ++) {
            int x = 0, y = 0;
            for (int j = 0; j <= i; j ++) x += s[j] - '0';
            for (int j = i+1; j < s.length(); j ++) y += s[j] - '0';
            if (x == y) {
                flag = 1;
                break;
            }
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
