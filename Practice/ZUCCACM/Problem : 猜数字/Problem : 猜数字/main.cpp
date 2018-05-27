//
//  main.cpp
//  Problem : 猜数字
//
//  Created by czf on 15/10/20.
//  Copyright © 2015年 czf. All rights reserved.
//


#include <cstdio>
#include <cmath>
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",(int)pow(2, n)-1);
    }
    return 0;
}
