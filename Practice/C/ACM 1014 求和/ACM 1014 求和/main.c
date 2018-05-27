//
//  main.c
//  ACM 1014 求和
//
//  Created by czf on 15/9/8.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x;
    int i;
   
    scanf("%d",&x);
    for (i = 1; i <= x; i ++) {
        printf("%d / %d = %d\n",x,i,x/i);
    }
    
    return 0;
}
