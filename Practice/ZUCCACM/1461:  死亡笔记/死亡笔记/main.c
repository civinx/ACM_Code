//
//  main.c
//  死亡笔记
//
//  Created by czf on 15/10/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int day,num;
        scanf("%d%d",&day,&num);
        double sum = 0;
        for (int i = 0; i < day; i ++) {
            int x;
            scanf("%d",&x);
            sum += x;
        }
        printf("%.6f\n",sum/(num-1));
    }
    return 0;
}
