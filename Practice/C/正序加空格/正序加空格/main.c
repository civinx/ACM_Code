//
//  main.c
//  正序加空格
//
//  Created by czf on 15/8/7.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    int t;
    int mask = 1;
    
    scanf("%d",&x);
    t = x;
    while (t > 9) {
        t /= 10;
        mask *= 10;
    }
    while (mask > 0){
        int d = x / mask;
        printf("%d",d);
        if(mask > 1){
            printf(" ");
        }
        x %= mask;
        mask /= 10;
    }
        
    return 0;
}
