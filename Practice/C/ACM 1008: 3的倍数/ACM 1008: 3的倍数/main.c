//
//  main.c
//  ACM 1008: 3的倍数
//
//  Created by czf on 15/8/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    int i;
    int k;
    int cnt;
    
    
    do {
        scanf("%d",&x);
        cnt = 0;
        if(x != 0){
            k = x;
            for (i = 0; i < k; i ++) {
                scanf("%d",&x);
                if (x % 3 == 0) {
                    cnt ++;
                }
            }
            printf("%d\n",cnt);
            
        }
    }while (x != 0);
    return 0;
}
