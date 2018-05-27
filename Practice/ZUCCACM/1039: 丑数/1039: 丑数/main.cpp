//
//  main.cpp
//  1039: 丑数
//
//  Created by czf on 15/11/23.
//  Copyright © 2015年 czf. All rights reserved.
//

#include<stdio.h>
#define min(a,b) (a<b?a:b)
#define minplus(a,b,c,d) min(min(a,b),min(c,d))
int a[5850];//存放丑数

int main(){
    int p2, p3 ,p5 ,p7, n = 1;
    a[1] = p2 = p3 = p5 = p7 = 1;
    while(a[n]<2000000000){
        a[++n] = minplus(2*a[p2],3*a[p3],5*a[p5],7*a[p7]);
        if(a[n]==2*a[p2]) p2++;
        if(a[n]==3*a[p3]) p3++;
        if(a[n]==5*a[p5]) p5++;
        if(a[n]==7*a[p7]) p7++;
    }
    for (int i = 1; i < 5850; i ++) {
        printf("%d\n",a[i]);
    }
    return 0;
}
