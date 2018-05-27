//
//  main.c
//  平均数 数组1
//
//  Created by czf on 15/8/21.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {
    int x;
    int number[100];
    int cnt = 0;
    double sum = 0;
    
    scanf("%d",&x);
    while (x != -1) {
        scanf("%d",&x);
        sum += x;
        cnt ++;
        number[cnt] = x;
    }
    
    double average = sum / cnt;
    
    for (int i = 1; i <= cnt; i ++) {
        if (number[i] >= average){
            printf("%d ",number[i]);
        }
    }
    return 0;
}
