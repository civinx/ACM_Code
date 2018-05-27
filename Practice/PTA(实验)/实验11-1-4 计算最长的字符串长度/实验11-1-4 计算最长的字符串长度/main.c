//
//  main.c
//  实验11-1-4 计算最长的字符串长度
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10
#define MAXS 20

int max_len( char *s[], int n );

int main()
{
    int i, n;
    char *string[MAXN] = {NULL};
    
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        string[i] = (char *)malloc(sizeof(char)*MAXS);
        scanf("%s", string[i]);
    }
    printf("%d\n", max_len(string, n));
    
    return 0;
}

int max_len( char *s[], int n )
{
    int i;
    int max=strlen(s[0]);
    for (i=1;i<n;i++)
    {
        if(strlen(s[i])>max)
            max=strlen(s[i]);
    }
    return max;
}
