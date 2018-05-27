//
//  main.c
//  判断0-9出现个数
//
//  Created by czf on 15/8/21.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    const int number = 10;
    int i;
    int count[number];
    int x;
    
    for (i = 0; i < number; i ++) {
        count[i] = 0;
    }
    
    scanf("%d",&x);
    while (x != -1) {
        if (x>=0 && x<=9) {
            count[x] ++;
        }
        scanf("%d",&x);
    }
    
    for (i = 0; i < number; i++) {
        printf("%d出现了%d次。\n",i,count[i]);
    }
    return 0;
}
