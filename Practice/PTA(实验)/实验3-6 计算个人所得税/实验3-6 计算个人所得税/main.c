//
//  main.c
//  实验3-6 计算个人所得税
//
//  Created by czf on 15/10/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    double rate = 0;
    double shui;
    double salary;
    
    scanf("%lf",&salary);
    
    if (salary > 1600 && salary <= 2500) {
        rate = 0.05;
    }
    else if (salary > 2500 && salary <= 3500){
        rate = 0.1;
    }
    else if (salary > 3500 && salary <= 4500){
        rate = 0.15;
    }
    else if (salary > 4500){
        rate = 0.2;
    }
    
    if (salary <= 1600) {
        printf("0.00");
    }
    else{
        shui = rate *(salary - 1600);
        
        printf("%.2lf",shui);
    }
    return 0;
}
