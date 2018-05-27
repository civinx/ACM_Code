//
//  main.c
//  P1102
//
//  Created by czf on 15/9/12.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int high[10];
    int taotaohigh;
    int x = 0;
    int cnt = 0;
    int i;
    
    for (i = 0; i < 10; i ++) {
        scanf("%d",&high[x]);
        x ++;
    }
    scanf("%d",&taotaohigh);
    
    for (i = 0; i < 10; i ++) {
        if ((taotaohigh + 30) >= high[i]) {
            cnt ++;
        }
    }
    printf("%d",cnt);
    return 0;
}
