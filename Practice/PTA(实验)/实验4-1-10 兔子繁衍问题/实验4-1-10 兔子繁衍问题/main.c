//
//  main.c
//  实验4-1-10 兔子繁衍问题
//
//  Created by czf on 15/9/22.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int fbnq(int x);

int main() {
    int n;
    int x;
    
    scanf("%d",&x);
    
    n = 1;
    
    while (fbnq(n) < x) {
        n ++;
    }
    
    printf("%d",n);
    
    return 0;
}

int fbnq(int x){
    if (x == 1 || x == 2) {
        return 1;
    }
    else{
        return fbnq(x - 1) +fbnq(x - 2);
    }
}