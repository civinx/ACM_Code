//
//  main.c
//  实验6-8 简单计算器
//
//  Created by czf on 15/9/22.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char yunsuanfu = '0';
    int result;
    int num;
    int flag = 0;
    
    scanf("%d",&result);
    scanf("%c",&yunsuanfu);
    while (yunsuanfu != '=') {
        scanf("%d",&num);
        switch (yunsuanfu) {
            case '+':
                result += num;
                break;
            case '-':
                result -= num;
                break;
            case '*':
                result *= num;
                break;
            case '/':
                if (num != 0) {
                    result /= num;
                }
                else{
                    flag = 1;
                }
                break;
            default:
                flag = 1;
                break;
        }
        scanf("%c",&yunsuanfu); //这句话放的位置很关键
    }
    
    if (flag == 0) {
        printf("%d",result);
    }
    else{
        printf("ERROR");
    }
    return 0;
}
