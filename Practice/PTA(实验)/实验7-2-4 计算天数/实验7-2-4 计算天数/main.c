//
//  main.c
//  实验7-2-4 计算天数
//
//  Created by czf on 15/9/24.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int year,month,day;
    int i;
    int yearday = 0;
    int leap;
    int monthday[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
    };
    scanf("%d/%d/%d",&year,&month,&day);
    
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    
    for (i = 1; i < month; i ++) {
        yearday += monthday[leap][i];
    }
    
    yearday += day;
    
    printf("%d",yearday);
    
    return 0;
}
