//
//  main.c
//  实验7-2-10 简易连连看
//
//  Created by czf on 15/9/24.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    char a[8][8];
    char b;
    int N;
    int n;
    int i,j,k;
    int x1,y1,x2,y2;
    int sum;
    int cnt_success = 0;
    int cnt_fault = 0;
    
    scanf("%d",&N);
    
    sum = 4*N*N;
    
    for (i = 0; i < N * 2; i ++) {
        for (j = 0; j < N * 2; ) {
            scanf("%c",&b);
            if (b >= 'A' && b <= 'Z') {
                a[i][j] = b;
                j ++;                 //注意读入字母数组时滤去除字母以外的字符！！！
            }
        }
    }
    
    scanf("%d",&n);
    
    for (k = 0; k < n; k ++) {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if ((a[x1 - 1][y1 - 1] == a[x2 - 1][y2 - 1]) && (a[x1 - 1][y1 - 1] != '*') && (a[x2 - 1][y2 - 1] != '*')) {
            a[x1 - 1][y1 - 1] = a[x2 - 1][y2 - 1] = '*';
            cnt_success += 2;
            if (cnt_success == sum) {
                printf("Congratulations!");
                break;
            }
            for (i = 0; i < 2 * N; i ++) {
                for (j = 0; j < 2 * N; j ++) {
                    printf("%c",a[i][j]);
                    if (j != 2*N - 1) {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
        else{
            printf("Uh-oh\n");
            cnt_fault ++;
        }
        if (cnt_fault == 3) {
            printf("Game Over");
            break;
        }
    }
    return 0;
}
