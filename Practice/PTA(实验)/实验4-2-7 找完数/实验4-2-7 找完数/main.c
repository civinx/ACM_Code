//
//  main.c
//  实验4-2-7 找完数
//
//  Created by czf on 15/9/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
int Isperfect(int x) { //判断是否是完数
    int sum = 0;
    int ret = 0;
    for (int i = 1; i < x; i ++) {//A处
        if (x % i == 0) sum += i;
    }
    if (x == sum || x == 1) ret = 1; //因为如果x==1，进不了A处循环，然而1又是一个完数。
    return ret;
}

int main() {
    int m, n, flag = 1;
    scanf("%d%d",&m,&n);
    for (int i = m; i <= n; i ++) { //遍历
        if (Isperfect(i)){
            flag = 0; //一旦有一个完数 flag就变成0
            printf("%d = 1",i);
            for (int j = 2; j < i; j ++) {
                if (i % j == 0) printf(" + %d",j);
            }
            printf("\n");
        }
    }
    if (flag) printf("None\n");
    return 0;
}
