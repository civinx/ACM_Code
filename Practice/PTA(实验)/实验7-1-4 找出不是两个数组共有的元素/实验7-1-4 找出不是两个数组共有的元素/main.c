//
//  main.c
//  实验7-1-4 找出不是两个数组共有的元素
//
//  Created by czf on 15/10/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int n_a;
    int n_b;
    int a[20];
    int b[20];
    int c[20];
    int i,j,k,m;
    int flag;
    
    scanf("%d",&n_a);
    for (i = 0; i < n_a; i ++) {
        scanf("%d",&a[i]);
    }
    
    scanf("%d",&n_b);
    for (i = 0; i < n_b; i ++) {
        scanf("%d",&b[i]);
    }
    
    k = 0;
    for (i = 0; i < n_a; i ++) {
        flag = 1;
        for (j = 0; j < n_b; j ++) {
            if (a[i] == b[j]) {
                flag = 0;
            }
        }
        for (m = 0; m < k; m ++) {
            if (a[i] == c[m]) {
                flag = 0;
            }
        }
        if (flag) {
            c[k] = a[i];
            k ++;
        }
    }
    
    for (i = 0; i < n_b; i ++) {
        flag = 1;
        for (j = 0; j < n_a; j ++) {
            if (b[i] == a[j]) {
                flag = 0;
            }
        }
        for (m = 0; m < k; m ++) {
            if (b[i] == c[m]) {
                flag = 0;
            }
        }
        if (flag) {
            c[k] = b[i];
            k ++;
        }
    }
    
    for (i = 0; i < k; i ++) {
        printf("%d",c[i]);
        if (i != k - 1) {
            printf(" ");
        }
    }
    return 0;
}
