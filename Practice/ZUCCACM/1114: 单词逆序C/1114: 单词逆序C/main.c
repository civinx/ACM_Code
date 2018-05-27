//
//  main.c
//  1114: 单词逆序C
//
//  Created by czf on 15/11/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define maxn 105
int main() {
    int t;
    char a[maxn] = "";
    scanf("%d",&t);
    gets(a);
    while (t--) {
        gets(a);
        int flag = 0;
        int i;
        for (i = 0; a[i] != '\0'; i ++) {
            if (a[i] == ' ') {
                if (flag) printf(" ");
                else flag = 1;
                for (int j = i - 1; j != -1 && a[j] != ' '; j--) {
                    printf("%c",a[j]);
                }
            }
        }
        if (flag) printf(" ");
        for (i = i-1; i != -1 && a[i] != ' '; i --) {
            printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
