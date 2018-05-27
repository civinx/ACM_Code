//
//  main.c
//  练习4-10 找出最小值
//
//  Created by czf on 15/9/16.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int num;
    int x;
    int tidai;
    int i;
    
    scanf("%d%d",&num,&x);
    tidai = x;
    for (i = 1; i < num; i++) {
        scanf("%d",&x);
        if (x < tidai) {
            tidai = x;
        }
    }
    printf("min = %d",tidai);
    
    return 0;
}
