//
//  main.c
//  实验9-2 时间换算
//
//  Created by czf on 15/10/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

struct time{
    int xiaoshi;
    int fenzhong;
    int miao;
};

int main() {
    int n;
    struct time now;
    scanf("%d:%d:%d",&now.xiaoshi,&now.fenzhong,&now.miao);
    scanf("%d",&n);
    
    now.miao += n;
    
    if (now.miao >= 60) {
        now.miao %= 60;
        now.fenzhong ++;
    }
    
    
    now.fenzhong += (n / 60);
    
    if (now.fenzhong >= 60) {
        now.fenzhong %= 60;
        now.xiaoshi ++;
    }
    
    now.xiaoshi += (n/3600);
    
    if (now.xiaoshi > 23) {
        now.xiaoshi %= 24;
    }
    if (now.xiaoshi < 10) {
        printf("0");
    }
    printf("%d:",now.xiaoshi);
    if (now.fenzhong < 10) {
        printf("0");
    }
    printf("%d:",now.fenzhong);
    if (now.miao < 10) {
        printf("0");
    }
    printf("%d",now.miao);
    return 0;
}
