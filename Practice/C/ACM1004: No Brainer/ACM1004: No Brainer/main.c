//
//  main.c
//  ACM1004: No Brainer
//
//  Created by czf on 15/8/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int k;
    int k_1;
    int x,y;
    scanf("%d",&k);
    
    for (k_1 = 0; k_1 < k; k_1 ++) {
        scanf("%d %d",&x,&y);
        if (x < y) {
            printf("NO BRAINS");
        }
        else{
            printf("MMM BRAINS");
        }
        if (k_1 != k - 1) {
            printf("\n");
        }
    }
    return 0;
}
