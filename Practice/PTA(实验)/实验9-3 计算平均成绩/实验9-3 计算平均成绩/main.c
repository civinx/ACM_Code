//
//  main.c
//  实验9-3 计算平均成绩
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

struct student{
    char xuehao[6];
    char name[10];
    double score;
};
int main() {
    int n;
    int i;
    double sum;
    double average;
    struct student a[10];
    
    scanf("%d\n",&n);
    
    sum = 0;
    for (i = 0; i < n; i ++) {
        scanf("%s%s%lf",a[i].xuehao,a[i].name,&a[i].score);
        sum += a[i].score;
    }
    
    average = sum / n;
    
    printf("%.2lf\n",average);
    
    for (i = 0; i < n; i ++) {
        if (a[i].score < average) {
            printf("%s %s\n",a[i].name,a[i].xuehao);
        }
    }
    
    return 0;
}
