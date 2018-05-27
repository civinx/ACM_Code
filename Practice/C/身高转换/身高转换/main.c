//
//  main.c
//  身高转换
//
//  Created by czf on 15/7/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    printf("请输入你的英制身高，如\"5 7\":");
    
    double foot;
    double inch;
    
    scanf("%lf %lf",&foot,&inch);
    
    
    printf("您的身高为%f",(((inch/12)+foot)*0.3048));





return 0;
}
