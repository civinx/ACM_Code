//
//  main.cpp
//  5-1 最大子列和问题 (在线算法)
//
//  Created by czf on 15/12/6.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
int a[10000 + 100];
int main(){
    int n; scanf("%d",&n);
    int l = 0, r = 0, temp = 0;
    int sum = 0, res = 0;
    int flag = 0;
    for (int i = 0; i < n; i ++) {
        scanf("%d",&a[i]);
        if (a[i] >= 0) flag = 1;
    }
    for (int i = 0; i < n; i ++) {
        sum += a[i];
        if (sum < 0) {
            temp = i + 1;
            sum = 0;
        }
        if (sum > res) {
            r = i;
            l = temp;
            res = sum;
        }
    }
    if (res == 0) {
        if (flag == 0) {
            printf("0 %d %d\n",a[0],a[n-1]);
        } else {
            printf("0 0 0\n");
        }
    } else  {
        printf("%d %d %d\n",res,a[l],a[r]);
    }
    
    return 0;
}