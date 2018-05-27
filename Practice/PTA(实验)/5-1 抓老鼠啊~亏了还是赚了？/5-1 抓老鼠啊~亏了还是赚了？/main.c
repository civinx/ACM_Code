//
//  main.c
//  5-1 抓老鼠啊~亏了还是赚了？
//
//  Created by czf on 15/10/29.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main() {
    char s[80];
    int day[80];
    for (int i = 0; i < 80; i ++) {
        day[i] = 1;
    }
    gets(s);
    int cost = 0;
    for (int i = 0; s[i] != '$'; i++) {
        if (day[i]>0 && s[i] == 'T') {
            printf("D");
            day[i+1] --;
            day[i+2] --;
            cost += 7;
        }
        else if (day[i]>0 && s[i] == 'C'){
            printf("!");
            day[i+1] = day[i+2] = 100;
            cost -= 3;
        }
        else if (day[i]>0 && s[i] == 'X'){
            printf("U");
            day[i+1] --;
        }
        else printf("-");
    }
    printf("\n");
    printf("%d",cost);
    return 0;
}
