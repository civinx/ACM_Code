//
//  main.cpp
//  1001 Sum Problem
//
//  Created by czf on 15/11/2.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int x;
    double y;
    while (scanf("%d",&x) != EOF) {
        int sum = 0;
        y = (1 + x) / 2.0;
        sum = y * x;
        printf("%d\n",sum);
        printf("\n");
    }
    return 0;
}
