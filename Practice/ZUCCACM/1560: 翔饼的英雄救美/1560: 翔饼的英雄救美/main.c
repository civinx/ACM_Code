//
//  main.c
//  1560: 翔饼的英雄救美
//
//  Created by czf on 15/10/6.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int h,u,d,N;
    int v_week;
    int v_day,v_day_max;
    int v_1_5;
    int day;
    int zushu;
    int i,j;
    int xingqi = 1;
    int gao;
    int flag;
    
    scanf("%d",&zushu);
    
    for (i = 0; i < zushu; i ++) {
        scanf("%d%d%d%d",&h,&u,&d,&N);
        v_day = u - d;
        v_week = u * 5 - 7 * d;
        v_1_5 = v_day * 4 + u;
        v_day_max = u;
        xingqi = 1;
        N *= 365;
        gao = 0;
        flag = 0;
        for (j = 1; j <= N; j ++) {
            if (xingqi >= 1 && xingqi <= 5) {
                gao += u;
                if (gao >= h) {
                    flag = 1;
                    break;
                }
                else{
                    gao -= d;
                }
            }
            if (xingqi == 6 || xingqi == 7) {
                gao -= d;
                if (xingqi == 7) {
                    xingqi = 0;
                }
            }
            xingqi ++;
        }
        if (flag) {
            printf("%d\n",j);
        }
        else{
            printf("-1\n");
        }
        
    }
    
    return 0;
}
//        flag = 1;
//        v_day = u - d;
//        v_week = u * 5 - 7 * d;
//        v_1_5 = v_day * 4 + u;
//        v_day_max = u;
//        day = 0;
//        if (v_day_max < h && v_day < 0) {
//            flag = 0;
//        }
//        if (v_1_5 < h && v_week < 0) {
//            flag = 0;
//        }
//        if (flag) {
//            while (v_day_max < h) {
//                if (v_1_5 < h) {
//                    h -= v_week;
//                    day += 7;
//                }
//                else{
//                    h -= v_day;
//                    day ++;
//                }
//            }
//            if (h != 0) {
//                day ++;
//            }
//            N *= 365;
//            
//            if (day < N) {
//                printf("%ld\n",day);
//            }
//            else{
//                printf("-1\n");
//            }
//        }
//        else{
//            printf("-1\n");
//        }

