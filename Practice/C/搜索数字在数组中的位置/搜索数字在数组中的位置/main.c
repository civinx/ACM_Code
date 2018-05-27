//
//  main.c
//  搜索数字在数组中的位置
//
//  Created by czf on 15/8/21.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int search(int x,int data[],int lengh);

int main(int argc, const char * argv[]) {
    int data[] = {9,29,32,45,6,45,8,3,1,43};
    int x;
    int loc;
    
    scanf("%d",&x);
    loc = search(x, data, sizeof(data)/sizeof(data[0]));
    if (loc != -1) {
        printf("%d在库中的位置是第%d位。",x,loc);
    }
    else{
        printf("该数据在库中不存在");
    }
    return 0;
}

int search(int x,int data[] ,int lengh){
    int ret = -1;
    for (int i = 0; i < lengh; i++) {
        if (x == data[i]) {
            ret = i + 1;
            break;
        }
    }
    return ret;
}