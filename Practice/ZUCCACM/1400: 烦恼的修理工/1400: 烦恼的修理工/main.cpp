//
//  main.cpp
//  1400: 烦恼的修理工
//
//  Created by czf on 15/11/9.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n, bk;
    while (scanf("%d%d",&n,&bk) == 2) {
        int high = 0;
        for (int i = 1; i <= n; i ++) {
            high += i;
            if (high == bk)
                high --;
        }
        printf("%d\n",high);
    }
    return 0;
}
