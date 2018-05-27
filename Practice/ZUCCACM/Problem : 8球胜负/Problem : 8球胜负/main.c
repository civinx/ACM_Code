//
//  main.c
//  Problem : 8球胜负
//
//  Created by czf on 15/10/19.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
int main() {
    int n;
    char x;
    while (scanf("%d",&n) == 1 && n) {
        if (n) getchar();
        int cnt_red = 0, cnt_yellow = 0;
        for (int i = 0; i < n; i ++) {
            x = getchar();
            if (x == 'R') cnt_red++;
            if (x == 'Y') cnt_yellow++;
            if (x == 'B'){
                if (cnt_red >= 7) {printf("Red\n"); continue;}
                else {printf("Yellow\n"); continue;}
            }
            if (x == 'L'){
                if (cnt_yellow >= 7) {printf("Yellow\n"); continue;}
                else {printf("Red\n"); continue;}
            }
            
        }
    }
    return 0;
}
