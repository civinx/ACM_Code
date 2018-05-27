//
//  main.c
//  找零计算器 if else
//
//  Created by czf on 15/7/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int price,bill;
    
    printf("请输入物品的金额:");
    scanf("%d",&price);
    printf("请输入票面:");
    scanf("%d",&bill);
    
    if (bill>price) {
        printf("找您%d元。",bill - price);
    }else if (bill == price){
        printf("您付的金额刚好。");
    }else{
        printf("您付的金额不够。");
    }
    
    return 0;
}
