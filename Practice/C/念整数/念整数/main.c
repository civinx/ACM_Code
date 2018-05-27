//
//  main.c
//  念整数
//
//  Created by czf on 15/8/7.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    int mask = 1;
    int t;
    int k;
    int n;
    
    scanf("%d",&x);
    if (x < 0) {
        t = -x;
        k = t;
        printf("fu ");
    }else{
        t = x;
        k = t;
    }
    while (t > 9) {
        t /= 10;
        mask *= 10;
    }
    while (mask > 0) {
        n = k / mask;
        switch (n) {
            case 1:
                printf("yi");
                break;
            case 2:
                printf("er");
                break;
            case 3:
                printf("san");
                break;
            case 4:
                printf("si");
                break;
            case 5:
                printf("wu");
                break;
            case 6:
                printf("liu");
                break;
            case 7:
                printf("qi");
                break;
            case 8:
                printf("ba");
                break;
            case 9:
                printf("jiu");
                break;
            case 0:
                printf("ling");
                break;
        }
        if (mask > 1) {
            printf(" ");
        }
        k %= mask;
        mask /= 10;
    }
    return 0;
}
