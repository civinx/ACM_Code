//
//  main.cpp
//  1121: PUŽ
//
//  Created by czf on 15/11/4.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
int main() {
    int a, b, high;
    while (scanf("%d%d%d",&a,&b,&high) == 3) {
        int day = 0;
        if (a < high){
            day = (high - a)/(a-b);
            if ((high - a)%(a-b) != 0) day ++;
        }
        day ++;
        printf("%d\n",day);
    }
    return 0;
}
