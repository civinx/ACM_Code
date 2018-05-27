//
//  main.c
//  ACM 1008 3的倍数
//
//  Created by czf on 15/9/10.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[]) {
    int cnt;
    int x;
    int n;
    int i;
    do{
        cnt = 0;
        scanf("%d",&n);
        for (i = 0; i < n; i ++) {
            scanf("%d",&x);
            if (x % 3 == 0) {
                cnt ++;
            }
        }
        if(n != 0){
            printf("%d\n",cnt);
        }
    }while (n != 0);
    return 0;
}
