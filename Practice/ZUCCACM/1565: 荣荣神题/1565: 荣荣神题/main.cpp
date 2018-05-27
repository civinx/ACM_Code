//
//  main.cpp
//  1565: 荣荣神题
//
//  Created by czf on 15/11/10.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int m;
        scanf("%d",&m);
        int cnt = 1;
        int temp = 1;
        while (temp) {
            temp = temp*10 + 1;
            temp %= m;
            cnt ++;
        }
        if (m == 1)
            cnt --;
        for (int i = 0; i < cnt; i ++) {
            printf("1");
        }
        putchar('\n');
    }
    return 0;
}
