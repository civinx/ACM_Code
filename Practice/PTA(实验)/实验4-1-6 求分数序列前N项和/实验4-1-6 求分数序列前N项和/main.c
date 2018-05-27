//
//  main.c
//  实验4-1-6 求分数序列前N项和
//
//  Created by czf on 15/9/20.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    double sum = 0;
    int n;
    int i;
    double fenzi,fenmu;
    double rongqi;
    
    fenzi = 2;
    fenmu = 1;
    
    scanf("%d",&n);
    
    for (i = 1; i <= n; i ++) {
        sum += fenzi / fenmu;
        rongqi = fenmu;
        fenmu = fenzi;
        fenzi = fenzi +rongqi;
    }
    
    
    printf("%.2f",sum);
    return 0;
}
