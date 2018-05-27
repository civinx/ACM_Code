//
//  main.c
//  实验7-2-3 求矩阵的局部极大值
//
//  Created by czf on 15/9/24.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include<stdio.h>
int main(){
    int a[20][20];
    int x,y;
    int i,j;
    int flag = 0;
    
    scanf("%d%d",&x,&y);
    
    for(i = 0 ; i < x ; i ++){
        for(j = 0 ; j < y ; j ++){
            scanf("%d",&a[i][j]);
        }
    }
    
    for(i = 1 ; i < x - 1 ; i ++){
        for(j = 1 ; j < y - 1; j ++){
            if(a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1]){
                printf("%d %d %d\n",a[i][j],i + 1,j + 1);
                flag = 1;
            }
        }
    }
    
    if(flag == 0){
        printf("None %d %d",x,y);
    }	
    return 0;		
}
