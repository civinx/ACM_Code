//
//  main.c
//  实验9-8 通讯录排序
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

struct friend{
    char name[11];
    double birthday;
    char phone[18];
};

int main() {
    struct friend a[10];
    struct friend temp;
    int n;
    int i,j;
    
    scanf("%d",&n);
    
    for (i = 0; i < n; i ++) {
        scanf("%s%lf%s",a[i].name,&a[i].birthday,a[i].phone);
    }
    
    for (i = 0; i < n - 1; i ++) {
        for (j = 0; j < n - i - 1; j ++) {
            if (a[j].birthday > a[j + 1].birthday ) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    for (i = 0; i < n; i ++) {
        printf("%s %.lf %s\n",a[i].name,a[i].birthday,a[i].phone);
    }
    
    return 0;
}
