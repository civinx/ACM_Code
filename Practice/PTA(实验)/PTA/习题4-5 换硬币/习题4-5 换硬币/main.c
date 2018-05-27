//
//  main.c
//  习题4-5 换硬币
//
//  Created by czf on 15/9/18.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int x;
    int fen1;
    int fen2;
    int fen5;
    int cnt = 0;
    
    scanf("%d",&x);
    
    for (fen5 = x / 5; (fen5 >= 1); fen5 --) { 
        for (fen2 = x / 2; (fen2 >= 1); fen2 --) {
            for (fen1 = x; (fen1 >= 1) >= 1; fen1 --) {
                if (fen1 + fen2 * 2 + fen5 * 5 == x ) {
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",fen5,fen2,fen1,fen5+fen2+fen1);
                    cnt ++;
                }
            }
        }
    }
    printf("count = %d",cnt);
    return 0;
}
