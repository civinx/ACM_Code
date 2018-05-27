//
//  main.cpp
//  1596: 题目什么的最麻烦了
//
//  Created by czf on 15/10/20.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        int cnt;
        scanf("%d",&n);
        if (n % 3 == 2) cnt = n / 3 + 2;
        else cnt = n / 3 + 1;
        printf("%d\n",cnt);
    }
    return 0;
}
