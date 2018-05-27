//
//  main.c
//  1564: 教你扣球带你飞
//
//  Created by czf on 15/10/8.
//  Copyright © 2015年 czf. All rights reserved.
//

#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c,d,e;
    double buchang;
    double right;
    double temp;
    int n;
    int i;
    double x1,y1,r;
    
    scanf("%d",&n);
    
    for(i = 0 ;i < n ;i ++){
        scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e);
        if(a != c){
            printf("-1\n");
            continue;
        }
        if (a == 0 || c == 0) {
            printf("-1\n");
            continue;
        }
        if(a == c && a != 1){
            temp = a;
            a /= temp;
            b /= temp;
            c /= temp;
            d /= temp;
            e /= temp;
        }
        right = -e;
        buchang = (b / 2) * (b / 2) + (d / 2) * (d / 2);
        right += buchang;
        if(right <= 0){
            printf("-1\n");
            continue;
        }
        r = sqrt(right);
        x1 = -(b / 2);
        y1 = -(d / 2);

        printf("%.5f %.5f %.5f\n",x1,y1,r);
    }
    
}
