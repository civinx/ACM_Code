//
//  main.c
//  实验9-1 计算职工工资
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

struct staff{
    char name[80];
    double jiben;
    double fudong;
    double zhichu;
    double shifa;
};
int main() {
    int n;
    int i;
    struct staff a;
    scanf("%d",&n);
    
    for (i = 0; i < n; i ++) {
        scanf("%s%lf%lf%lf",a.name,&a.jiben,&a.fudong,&a.zhichu);
        a.shifa = a.jiben + a.fudong - a.zhichu;
        printf("%s %.2lf\n",a.name,a.shifa);
    }
    return 0;
}
