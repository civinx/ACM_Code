//
//  main.c
//  分解质因数
//
//  Created by czf on 15/8/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

void explode(int x);

int main(int argc, const char * argv[]) {
    int x;  //x为输入数据
    
    scanf("%d",&x); //输入数据
    
    printf("%d=",x);    //首先输出一个x=?的格式
    
    if (x != 1) {
        explode(x); //如果x不等于1，进入分解函数
    }
    else{
        printf("1");    //如果x等于1 直接输出
    }
        return 0;
}

void explode(int x){
    int i = 2;  // 定义i不停地除x
    while (x > 1) {
        if (x % i == 0) {
            printf("%d",i); //如果x被i整除 输出那个i
            if (i != x) {   // 若i x不相等 则说明其还未分解完全，接下来输出x号
                printf("x");
            }
            x /= i;
        }
        else{
            i++;
        }
    }
}