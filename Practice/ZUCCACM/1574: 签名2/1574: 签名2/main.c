//
//  main.c
//  1574: 签名2
//
//  Created by czf on 15/10/9.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int t;
    int i,j;
    int n;
    int min;
    int a[1010];
    
    scanf("%d",&t);
    
    for (j = 0; j < t; j ++) {
        scanf("%d",&n);
        for (i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
        }
        min = 0;
        for (i = 1; i < n; i ++) {
            if (a[i] < a[min]) {
                min = i;
            }
        }
        printf("%d\n",min + 1);
    }
    return 0;
}
