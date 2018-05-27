//
//  main.c
//  ACM1002斐波那契数列
//
//  Created by czf on 15/8/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    long long fbnq[1000000] = {1,1};
    int i;
    int n;
    int x;
    int k;
    int mask = 1;
    long long y;
    
    scanf("%d",&n);//输入组数
    
    for (i = 0; i < n; i ++) {//判断读入的组数
        scanf("%d",&x);
        mask = 1;//mask用来最后提取结果的首位
        for (k = 2; k < x; k ++) {
            fbnq[k] =fbnq[k - 1] + fbnq[k - 2];//给数组赋值
        }
//        printf("%lld\t",fbnq[k - 1]);
        if (fbnq[k - 1] < 10) {
            printf("%lld",fbnq[k - 1]);//如果结果是个位数 直接输出
        }
        else{
            y = fbnq[k - 1];
            while (y / 10 != 0) {
                y /= 10;
                mask *= 10;  //如果结果不止一位，计算结果的位数 比如结果是144 mask是100
            }
            printf("%lld %lld",fbnq[k - 1] / mask,fbnq[k - 1] % 10);//输出首位和尾位
        }
        if (i != n - 1) {
            printf("\n");//非最后一位空行
        }
    }
    return 0;
}
