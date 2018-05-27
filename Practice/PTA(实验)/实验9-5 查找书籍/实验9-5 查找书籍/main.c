//
//  main.c
//  实验9-5 查找书籍
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//
#include <stdio.h>

struct book{
    char name[31];
    double price;
};
int main() {
    
    struct book a,max,min;
    int n;
    int i;
    scanf("%d\n",&n);
    
    for (i = 0; i < n; i ++) {
        
        gets(a.name);
        
        scanf("%lf",&a.price);
        
        if (i == 0) {
            max = a;
            min = a;
        }
        if (a.price > max.price) {
            max = a;
        }
        if (a.price < min.price) {
            min = a;
        }
        if (i != n- 1) {
            getchar();
        }
        
    }
    
    printf("%.2lf, %s\n",max.price,max.name);
    printf("%.2lf, %s\n",min.price,min.name);
    return 0;
}