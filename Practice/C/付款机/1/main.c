//
//  main.c
//  1
//
//  Created by czf on 15/7/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int cash = 0;
    int price = 0;
    
    printf("请输入物品的总价：");
    
    scanf("%d",&price);
    
    printf("请输入支付的金额：");
    
    scanf("%d",&cash);
    
    int change = cash - price;
    
    printf("找您%d元",change);
    
    return 0;
    
    
    
    
    
}
