//
//  main.c
//  电台RS
//
//  Created by czf on 15/7/28.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    int a;
    int b;
    
    scanf("%d",&x);
    if (x>=11&&x<=59) {
        a = x/10;
        b = x%10;
    }else{
        printf("输入的值不在范围内。");
    }switch (b){
        case 1:
            printf("Faint signals, barely perceptible, ");
            break;
        case 2:
            printf("Very weak signals, ");
            break;
        case 3:
            printf("Weak signals, ");
            break;
        case 4:
            printf("Fair signals, ");
            break;
        case 5:
            printf("Fairly good signals, ");
            break;
        case 6:
            printf("Good signals, ");
        case 7:
            printf("Moderately strong signals, ");
            break;
        case 8:
            printf("Strong signals, ");
            break;
        case 9:
            printf("Extremely strong signals, ");
            break;
        default:
            break;
    }
    switch (a) {
        case 1:
            printf("unreadable.");
            break;
        case 2:
            printf("barely readable, occasional words distinguishable.");
            break;
        case 3:
            printf("readable with considerable difficulty.");
            break;
        case 4:
            printf("readable with practically no difficulty.");
            break;
        case 5:
            printf("perfectly readable.");
            break;
        default:
            break;
    }
        return 0;
}
/*
 1---Unreadable
 2---Barely readable, occasional words distinguishable
 3---Readable with considerable difficulty
 4---Readable with practically no difficulty
 5---Perfectly readable
 报告第二位是S，共分九个级别，用1—9中的一位数字表示
 1---Faint signals, barely perceptible
 2---Very weak signals
 3---Weak signals
 4---Fair signals
 5---Fairly good signals
 6---Good signals
 7---Moderately strong signals
 8---Strong signals
 9---Extremely strong signals
*/