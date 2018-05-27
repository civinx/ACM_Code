//
//  main.c
//  实验9-7 找出总分最高的学生
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

struct student{
    char xuehao[6];
    char name[10];
    int c1;
    int c2;
    int c3;
    int sum;
};

int main() {
    int n;
    int i;
    
    struct student s1,max;
    scanf("%d",&n);
    
    for (i = 0; i < n; i ++) {
        scanf("%s%s%d%d%d",s1.xuehao,s1.name,&s1.c1,&s1.c2,&s1.c3);
        s1.sum = s1.c1 + s1.c2 + s1.c3;
        if (i == 0) {
            max = s1;
        }
        if (s1.sum > max.sum) {
            max = s1;
        }
    }
    
    printf("%s %s %d",max.name,max.xuehao,max.sum);
    
    return 0;
}
