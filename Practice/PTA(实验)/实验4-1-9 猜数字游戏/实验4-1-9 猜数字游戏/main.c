//
//  main.c
//  实验4-1-9 猜数字游戏
//
//  Created by czf on 15/9/28.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int n;
    int i;
    int x;
    int num;
    int cnt = 0;
    int flag = 1;
    
    scanf("%d%d",&x,&n);
    
    for (i = 0; i < n; i ++) {
        scanf("%d",&num);
        if (num < 0) {
            flag = 1;
            break;
        }
        if (num < x) {
            if (cnt == n) {
                flag = 1;
                break;
            }
            printf("Too small\n");
            cnt ++;
        }
        else if (num > x){
            if (cnt == n) {
                flag = 1;
                break;
            }
            printf("Too big\n");
            cnt ++;
        }
        else{
            flag = 0;
            cnt ++;
            break;
        }
    }
    if (flag == 1) {
        printf("Game Over");
    }
    else if (flag == 0){
        if (cnt == 1) {
            printf("Bingo!");
        }
        else if (cnt <= 3){
            printf("Lucky You!");
        }else if (cnt > 3){
            printf("Good Guess!");
        }
    }
    return 0;
}
