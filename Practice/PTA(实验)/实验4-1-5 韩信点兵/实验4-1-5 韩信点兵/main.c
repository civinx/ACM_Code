//
//  main.c
//  实验4-1-5 韩信点兵
//
//  Created by czf on 15/9/25.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
int main() {
    int i;
    for (i = 1; ; i ++) {
        if (i % 5 == 1 && i % 6 == 5 && i % 7 == 4 && i % 11 == 10) {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
