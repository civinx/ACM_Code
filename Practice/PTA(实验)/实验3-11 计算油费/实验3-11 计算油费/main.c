//
//  main.c
//  实验3-11 计算油费
//
//  Created by czf on 15/9/23.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int type;
    int volume;
    char serv;
    double price = 0;
    double discount = 0;
    
    scanf("%d %d %c",&volume,&type,&serv);
    
    if (serv == 'm') {
        discount = 0.95;
    }
    else{
        discount = 0.97;
    }
    if (type == 90) {
        price = 6.95 * volume;
    }
    else if (type == 93) {
        price = 7.44 * volume;
    }
    else if (type == 97) {
        price = 7.93 * volume;
    }
    price *= discount;
    
    printf("%.2lf",price);
    
    return 0;
}
