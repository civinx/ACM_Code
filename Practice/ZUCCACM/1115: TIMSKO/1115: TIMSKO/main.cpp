//
//  main.cpp
//  1115: TIMSKO
//
//  Created by czf on 15/11/5.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int boy, girl, k;
    while (scanf("%d%d%d",&girl,&boy,&k) == 3) {
        while (k) {
            if (girl*1.0/boy >= 2)
                girl --;
            else boy --;
            k --;
        }
        int res = girl/2 < boy ? girl/2:boy;
        printf("%d\n",res);
    }
    return 0;
}
