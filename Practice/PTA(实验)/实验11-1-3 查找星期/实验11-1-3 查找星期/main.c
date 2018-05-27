//
//  main.c
//  实验11-1-3 查找星期
//
//  Created by czf on 15/10/2.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAXS 80

int getindex( char *s );

int main()
{
    int n;
    char s[MAXS];
    
    scanf("%s", s);
    n = getindex(s);
    if ( n==-1 ) printf("wrong input!\n");
    else printf("%d\n", n);
    
    return 0;
}

int getindex( char *s ){
    int ret;
    int i;
    char a[7][MAXS] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    for (i = 0; i < 7 ; i ++) {
        if (strcmp(s,a[i]) == 0) {
            break;
        }
    }
    
    if (i == 7) {
        ret = -1;
    }
    else{
        ret = i;
    }
    return ret;
}
