//
//  main.c
//  1字数统计（5分）
//
//  Created by czf on 15/11/4.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int cnt[11] = {0};
    char x;
    int temp = 0;
    int flag = 0;
    while ((x = getchar()) != EOF) {
        if (!temp) if (x == '\'' || x == '-') flag = 1;
        if (temp) if (x == '\'' || x == '-') temp ++;
        if ((x >= 'a' && x <= 'z')||(x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')){
            temp ++;
            if (flag) {
                temp ++;
                flag = 0;
            }
        }
        else if (temp && x != '\'' && x != '-'){
            cnt[0] ++;
            if (temp <= 10)
            cnt[temp] ++;
            temp = 0;
        }
    }
    for (int i = 0; i < 11; i ++) {
        if (i) printf(" ");
        printf("%d",cnt[i]);
    }
    return 0;
}
