//
//  main.c
//  ACM 1006黑色星期五
//
//  Created by czf on 15/9/10.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    int i;
    int k;
    int n;
    int cnt;
    int chazhi;
    int day;
    int a[13]={0,12,43,71,102,132,163,193,224,255,285,316,346};
    
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d",&x);
        cnt = 0;
        for (k = 1; k <= 12; k++) {
            
            chazhi = ((x - 2000) / 4) - ((x - 2000)/ 100);
            if (x >= 2400) {
                chazhi ++;
            }
            if (x >= 2800) {
                chazhi ++;
            }
            if(((x % 4 == 0 && x%100 !=0)||(x % 400 == 0))&&(k<3)){
                chazhi --;
            }
            
            day = a[k] + chazhi*366 + (x - 2001 - chazhi)*365;

            if (day % 7 == 4) {
                cnt ++;
            }
        }
        printf("%d",cnt);
        if (i != n - 1) {
            printf("\n");
        }
    }
    return 0;
}
