//
//  main.c
//  习题3-2 高速公路超速处罚
//
//  Created by czf on 15/9/19.
//  Copyright (c) 2015年 czf. All rights reserved.
//


#include <stdio.h>
int main(){
    double speed;
    double limit;
    int cha;
    double baifenbi;
    
    scanf("%lf%lf",&speed,&limit);
    
    if (speed <= limit) {
        printf("OK");
    }else{
        cha = speed - limit;
        baifenbi = (cha / limit) * 100;
        if (baifenbi >= 10 && baifenbi <= 49) {
            printf("Exceed %.f%%. Ticket 200",baifenbi);
        }
        else if (baifenbi >= 50){
            printf("Exceed %.f%%. License Revoked",baifenbi);
        }
        else{
            printf("OK");
        }
    }
    return 0;
}


