//
//  main.cpp
//  1103: 海盗分金
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
        int n,m;
        scanf("%d%d",&n,&m);
        m -= (n+1)/2 - 1;
        printf("%d\n",m);
    }
    return 0;
}
