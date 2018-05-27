//
//  main.cpp
//  1484: Problem A
//
//  Created by czf on 15/11/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int a, b, c, t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d",&a,&b,&c);
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        printf("%d\n",b);
    }
    return 0;
}
