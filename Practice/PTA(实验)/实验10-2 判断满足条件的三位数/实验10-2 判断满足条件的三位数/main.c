//
//  main.c
//  实验10-2 判断满足条件的三位数
//
//  Created by czf on 15/9/26.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int search( int n );

int main()
{
    int number;
    
    scanf("%d",&number);
    printf("count=%d\n",search(number));
    
    return 0;
}

int search( int n){
    int cnt = 0;
    int cnt_2;
    int a,b,c;
    int i;
    
    for (i = 101; i <= n ; i ++) {
        if (i == (int)sqrt(i)*(int)sqrt(i)) {
            cnt_2 = 0;
            a = i / 100;
            b = i / 10 % 10;
            c = i % 10;
            if (a == b) {
                cnt_2 ++;
            }
            if (a == c) {
                cnt_2 ++;
            }
            if (b == c) {
                cnt_2 ++;
            }
            if (cnt_2 >= 1) {
                cnt ++;
            }
        }
    }
    return cnt;
}