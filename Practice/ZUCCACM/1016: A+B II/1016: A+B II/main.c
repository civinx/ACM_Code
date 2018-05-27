//
//  main.c
//  1016: A+B II
//
//  Created by czf on 15/10/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define maxn 50
int main() {
    char x[maxn],y[maxn];
    char sum[maxn];
    for (int i = 0; i < maxn; i ++){
        x[i] = '\0';
        y[i] = '\0';
        sum[i] = '\0';
    }
    while (scanf("%s%s",x,y) != EOF) {
        int n_x = strlen(x);
        int n_y = strlen(y);
        for (int i = 0; i < (n_x+1)/2; i ++) {
            int temp;
            temp = x[i];
            x[i] = x[n_x-1-i];
            x[n_x-1-i] = temp;
        }
        for (int i = 0; i < (n_y+1)/2; i ++) {
            int temp;
            temp = y[i];
            y[i] = y[n_y-1-i];
            y[n_y-1-i] = temp;
        }
        int i = 0;
        int k;
        int flag = 0;
        while (x[i] != '\0' || y[i] != '\0') {
            if (x[i] == '\0') k = (y[i] - '0');
            else if (y[i] == '\0') k = (x[i] - '0');
            else k = (x[i] - '0') + (y[i] - '0');
            if (flag){
                k ++;
                flag = 0;
            }
            if (k >= 10) {
                k %= 10;
                flag = 1;
            }
            sum[i] = '0' + k;
            i ++;
            if (x[i] == '\0' && y[i] == '\0'){
                if (flag) {
                    sum[i] = '1';
                }
            }
        }
        int n_sum = strlen(sum);
        for (int i = n_sum - 1; i >= 0; i --) {
            printf("%c",sum[i]);
        }
        printf("\n");
        for (int i = 0; i < maxn; i ++){
            x[i] = '\0';
            y[i] = '\0';
            sum[i] = '\0';
        }
    }
    return 0;
}
