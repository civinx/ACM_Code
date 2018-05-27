//
//  main.c
//  实验7-1-8 输出数组元素
//
//  Created by czf on 15/9/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a[10];
    int n;
    int i;
    int cha;
    int cnt = 0;
    
    scanf("%d",&n);
    
    for (i = 0 ; i < n; i ++) {
        scanf("%d",&a[i]);
    }
    
    for (i = 0; i < n - 1 ; i ++) {
        cha = a[i + 1] - a[i];
        printf("%d",cha);
        cnt ++;
        if (cnt % 3 != 0 && i != n - 2) {
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
    
    return 0;
}
