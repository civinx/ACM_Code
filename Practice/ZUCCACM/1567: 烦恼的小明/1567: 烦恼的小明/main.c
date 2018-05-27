//
//  main.c
//  1567: 烦恼的小明
//
//  Created by czf on 15/10/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
int fbnq(int n);

int main() {
    int n;
    int N;
    int j;
    int i;
    long long f,f1,f2;
    
    scanf("%d",&N);
    for (i = 0; i < N; i ++) {
        f1 = f2 = 1;
        scanf("%d",&n);
        if (n == 1 || n == 2) {
            printf("1\n");
        }
        else{
            for (j = 3; j <= n; j ++) {
                f = f1 + f2;
                f1 = f2;
                f2 = f;
            }
            printf("%d\n",f);
        }
    }
    return 0;
}

