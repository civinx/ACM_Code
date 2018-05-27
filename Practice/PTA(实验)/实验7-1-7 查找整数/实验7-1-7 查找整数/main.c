//
//  main.c
//  实验7-1-7 查找整数
//
//  Created by czf on 15/10/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int a[20];
    int x;
    int i;
    int n;
    int flag = 0;
    
    scanf("%d",&n);
    scanf("%d",&x);
    
    for (i = 0; i < n; i ++) {
        scanf("%d",&a[i]);
    }
    
    for (i = 0; i < n; i ++) {
        if (x == a[i]) {
            flag = 1;
            break;
        }
    }
    
    if (flag == 1) {
        printf("%d",i);
    }
    else{
        printf("Not Found");
    }
    
    return 0;
}
