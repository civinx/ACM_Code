//
//  main.c
//  实验3-5 查询水果价格
//
//  Created by czf on 15/9/22.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int num;
    int cnt = 0;
    scanf("%d",&num);
    printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
    while (num != 0 && cnt != 5) {
        switch (num) {
            case 1:
                printf("price = 3.00\n");
                break;
            case 2:
                printf("price = 2.50\n");
                break;
            case 3:
                printf("price = 4.10\n");
                break;
            case 4:
                printf("price = 10.20\n");
                break;
            default:
                printf("price = 0.00\n");
                break;
        }
        cnt ++;
        scanf("%d",&num);
    }
    
    return 0;
}
