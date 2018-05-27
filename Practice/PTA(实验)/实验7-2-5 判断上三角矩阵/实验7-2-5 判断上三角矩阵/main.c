//
//  main.c
//  实验7-2-5 判断上三角矩阵
//
//  Created by czf on 15/9/24.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>
int main(){
    int N;
    int n;
    int a[10][10];
    int i,j,k;
    int flag;
    
    scanf("%d",&N);
    for(k = 0; k < N ;k ++){
        flag = 1;
        scanf("%d",&n);
        for(i = 0 ; i < n ; i ++){
            for(j = 0 ; j < n; j ++){
                scanf("%d",&a[i][j]);
            }
        }
        
        for(i = 0 ; i < n ; i ++){
            for(j = 0 ; j < n ; j ++){
                if(i > j){
                    if(a[i][j] != 0){
                        flag = 0;
                    }
                }
            }
        }
        
        if(flag == 1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
