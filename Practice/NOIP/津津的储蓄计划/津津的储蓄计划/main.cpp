//
//  main.cpp
//  津津的储蓄计划
//
//  Created by czf on 2017/1/29.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
using namespace std;

int main() {
    int sum = 0, tot = 0, i;
    for (i = 0; i < 12; i ++) {
        sum += 300;
        int x; scanf("%d",&x);
        sum -= x;
        if (sum < 0) {
            printf("%d\n",-i-1);
            break;
        }
        tot += sum / 100 * 100;
        sum -= sum / 100 * 100;
    }
    if (i == 12) {
        printf("%.f\n",tot*1.2 + sum);
    }
    return 0;
}
