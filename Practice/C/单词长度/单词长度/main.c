//
//  main.c
//  单词长度
//
//  Created by czf on 15/10/31.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main() {
    char a[100];
    int cnt = 0;
    gets(a);
    int i = 0;
    while (a[i] != '.') {
        if (a[i] != ' ') cnt ++;
        else cnt = 0;
        if (a[i] != ' ' && a[i+1] == ' ')
            printf("%d ",cnt);
        else if (a[i] != ' ' && a[i+1] == '.')
            printf("%d",cnt);
        i ++;
    }
    return 0;
}
