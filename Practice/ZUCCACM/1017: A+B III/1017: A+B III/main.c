//
//  main.c
//  1017: A+B III
//
//  Created by czf on 15/10/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
int main() {
    char x;
    int num;
    int sum;
    int last;
    while ((x = getchar()) != EOF) {
        ungetc(x, stdin);
        sum = 0;
        int flag = 0;
        while ((x = getchar()) != '\n') {
            if (x == '=') {
                flag = 1;
            }
            if (x >= '0' && x <= '9' && flag == 0) {
                ungetc(x, stdin);
                scanf("%d",&num);
                sum += num;
            }
            if (x >= '0' && x <= '9' && flag) {
                ungetc(x, stdin);
                scanf("%d",&last);
                if (sum == last) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}
