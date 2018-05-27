//
//  main.c
//  BJT转化为UTC
//
//  Created by czf on 15/7/28.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x = 0;
    int a,b;
    int c = 0;
    
    scanf("%d",&x);
    if (x<100&&x>=60) {
        printf("输入时间不在正常范围内");
    }else if (x%100>=60) {
        printf("输入时间不在正常范围内");
    }else if (x>=800&&x<=2359){
        a = x/100-8;
        b = x%100;
        c = a*100 + b;
    }else if (x>=100&&x<800){
        a = x/100 - 8 +24;
        b = x%100;
        c = a*100 + b;
    }else if (x<60){
        c = 1600 + x;
    }else
        printf("输入时间不在正常范围内");
        printf("%d",c);
    
    return 0;
}
