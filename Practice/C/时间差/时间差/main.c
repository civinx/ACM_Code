//
//  main.c
//  时间差
//
//  Created by czf on 15/7/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(){
    int hour1,mimute1;
    int hour2,minute2;
    
    printf("请输入较早的一个时间：");
    scanf("%d %d", &hour1, &mimute1);
    
    printf("请输入较晚的一个时间：");
    scanf("%d %d",&hour2,&minute2);
    
    int t1 = hour1*60 + mimute1;
    int t2 = hour2*60 + minute2;
    int t3 = t2 - t1;
    
    printf("这两个时间的时间差为%d小时%d分钟",t3/60,t3%60);
    
    return 0;
}
