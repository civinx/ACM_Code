//
//  main.c
//  1577: 淌血霸的生日
//
//  Created by czf on 15/10/10.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int maxyue(int a,int b);

int main() {
    int a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int x,y,z;
    int zushu,k;
    int cnt = 0;
    int i,j;
    int month = 0,day = 0;
    int x1,x2;
    
    scanf("%d",&zushu);
    
    for (k = 0; k < zushu; k ++) {
        cnt = 0;
        scanf("%d%d%d",&x,&y,&z);
        if ((z % 4==0&&z % 100!=0) || x % 400 == 0) {
            a[2] = 29;
        }
        for (i = 1; i <= 12; i ++) {
            for (j = 1; j <= a[i]; j ++) {
                x1 = maxyue(i, j);
                x2 = i*j/x1;
                if (x1 == x && x2 == y) {
                    month = i;
                    day = j;
                    cnt ++;
                }
            }
        }
        if (cnt == 1) {
            printf("Case #%d: %d/%02d/%02d\n",k + 1,z,month,day);
        }
        else if (cnt > 1){
            printf("Case #%d: 1\n",k + 1);
        }
        else{
            printf("Case #%d: -1\n",k + 1);
        }
    }
    
    
    return 0;
}

int maxyue(int a,int b){
    int t;
    while (b) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}