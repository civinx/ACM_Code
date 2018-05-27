//
//  main.c
//  ACM1001鸡兔同笼
//
//  Created by czf on 15/8/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n;
    int a;
    scanf("%d",&n);
    
    for (int i = 0; i < n; i ++) {
        scanf("%d",&a);
        
        if (a % 2 == 1) {
            printf("0 0");
        }
        else if (a % 4 != 0){
            printf("%d %d",a / 4 + 1,a / 2);
        }
        else{
            printf("%d %d",a / 4,a / 2);
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
    return 0;
}
