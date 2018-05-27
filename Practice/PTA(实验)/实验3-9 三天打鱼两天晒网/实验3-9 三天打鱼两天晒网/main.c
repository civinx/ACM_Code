//
//  main.c
//  实验3-9 三天打鱼两天晒网
//
//  Created by czf on 15/9/22.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int x;
    
    x = n % 5;
    
    if (x == 0 || x == 4) {
        printf("Drying in day %d",n);
    }
    else{
        printf("Fishing in day %d",n);
    }
    
    return 0;
}
