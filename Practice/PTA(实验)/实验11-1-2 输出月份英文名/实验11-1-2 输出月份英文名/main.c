//
//  main.c
//  实验11-1-2 输出月份英文名
//
//  Created by czf on 15/10/2.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

char *getmonth( int n );

int main()
{
    int n;
    char *s;
    
    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);
    
    return 0;
}

char *getmonth( int n ){
    char *name[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    if (n <= 0 || n > 12) {
        return NULL;
    }
    else{
        return name[n - 1];
    }
}