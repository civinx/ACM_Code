//
//  main.c
//  完数
//
//  Created by czf on 15/8/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int isPerfect(int x);

int main(int argc, const char * argv[]) {
    
    int a,b;
    int x;
    int jihao = 0;
    scanf("%d %d",&a,&b);
    for (x = a; x <= b; x ++) {
        if (isPerfect(x)) {
            jihao ++;
            if (jihao == 1) {
                printf("%d",x);
            }
            else{
                printf(" %d",x);
            }
            
        }
    }
    if (jihao == 0) {
        printf("NIL\n");
    }
    return 0;
}

int isPerfect(int x){
    int ret = 0;    //ret默认为0 当判断x为完数时 ret变为1。
    int i = 2;
    int k = 1;  //k为因子总和。
    
    
    while (i < x){
        if (x % i == 0) {
            k += i;
        }
        i ++;
        }
    if (k == x&&x!=1) {
        ret = 1;
    }
    return ret;
}