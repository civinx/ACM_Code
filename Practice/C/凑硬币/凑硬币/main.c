//
//  main.c
//  凑硬币
//
//  Created by czf on 15/8/6.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    int one,two,five;
//    int exit = 0;
    
    scanf("%d",&x);
    for (one = 1; one < x * 10; one ++) {
        for (two = 1; two < x * 10 / 2; two ++) {
            for (five = 1; five < x * 10 / 5 ; five ++) {
                if(one + two*2 + five*5 == x*10){
                    printf("一种方案是%d个一角%d个两角%d个五角",one,two,five);
                    goto out;
//                    exit = 1;
//                    break;
                }
            }
//            if (exit)break;
        }
//        if (exit)break;
    }
out:
    return 0;
}
