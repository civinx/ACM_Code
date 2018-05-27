//
//  main.c
//  1566: 2048
//
//  Created by czf on 15/10/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int zushu,z,N;
    int a[10];
    int i,j,k; //最后用j输出
    int yiwei;
    int cnt;
    
    scanf("%d",&zushu);
    
    for (z = 0; z < zushu; z ++) {
        
        scanf("%d",&N);
        yiwei = 0;
        cnt = 1;
        for (i = 0; i < N; i ++) {
            scanf("%d",&a[i]);
        }
        for (i = 0; i < N; i ++,cnt++) {
            if (cnt > N) {
                break;
            }
            if (a[i] == 0) {//检查到0的情况
                yiwei ++;
                for (j = i; j < N - 1; j ++) {
                    a[j] = a[j + 1];
                }
                a[N - yiwei] = 0;
                i -= 1;
                continue;
            }//检查到0的情况

            else{
                for (j = i + 1; j < N; j ++) {
                    if (a[i] == a[j]) {
                        a[i] *= 2;
                        a[j] = 0;
                        break;
                    }
                    else if(a[j] != 0){
                        break;
                    }
                }
            }
        }
        for (k = 0; k < N - 1; k ++) {
            printf("%d ",a[k]);
        }
        printf("%d",a[k]);
        
        printf("\n");
    }
    return 0;
}
