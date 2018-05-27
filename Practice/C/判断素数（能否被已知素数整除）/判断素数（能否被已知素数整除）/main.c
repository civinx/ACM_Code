//
//  main.c
//  判断素数（能否被已知素数整除）
//
//  Created by czf on 15/8/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int isPrime(int x,int Prime[],int cnt);

int main(int argc, const char * argv[]) {
    
    const int number = 100;
    int Prime[number] = {2};
    int x;
    int cnt = 1;
    
    for (x = 3; cnt < number; x ++) {
        if (isPrime(x,Prime,cnt)) {
            Prime[cnt ++] = x;
        }
    }
    
    for (int i = 0; i <number; i ++) {
        printf("%d",Prime[i]);
        if ((i + 1) % 5) {
            printf("\t");
        }
        else{
            printf("\n");
        }
    }
    return 0;
}

int isPrime(int x,int Prime[],int cnt){
    int ret = 1;
    int i;
    for (i = 0; i < cnt; i++) {
        if (x % Prime[i] == 0) {
            ret = 0;
            break;
        }
    }
    return ret;
}
