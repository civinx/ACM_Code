//
//  main.cpp
//  1201: 测试你是否和LTC水平一样高
//
//  Created by czf on 15/10/18.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>

int main() {
    int x,y,z,num;
    while (scanf("%d",&num) != EOF) {
        int flag = 0;
        for (x = 1; x <= 100; x ++) {
            for (y = 1; y <= 100; y ++) {
                for (z = 1; z <= 100; z ++) {
                    if (pow(x, 2) + pow(y, 2) + pow(z, 2) == num) {
                        printf("%d %d %d\n",x,y,z);
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
    }
    return 0;
}

