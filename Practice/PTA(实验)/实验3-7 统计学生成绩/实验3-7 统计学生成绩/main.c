//
//  main.c
//  实验3-7 统计学生成绩
//
//  Created by czf on 15/9/22.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int x;
    int n;
    int i;
    
    scanf("%d",&n);
    for (i = 1; i <= n; i ++) {
        scanf("%d",&x);
        if (x >= 90) {
            a ++;
        }
        else if (x < 90 && x >= 80){
            b ++;
        }
        else if (x < 80 && x >= 70){
            c ++;
        }
        else if (x < 70 && x >= 60){
            d ++;
        }
        else{
            e ++;
        }
    }
    
    printf("%d %d %d %d %d",a,b,c,d,e);
    
    return 0;
}
