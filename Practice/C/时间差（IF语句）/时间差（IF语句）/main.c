//
//  main.c
//  时间差（IF语句）
//
//  Created by czf on 15/7/27.
//  Copyright (c) 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int h1,m1,h2,m2,h3,m3,x;
    scanf("%d%d",&h1,&m1);
    scanf("%d%d",&h2,&m2);
    h3=h1-h2;
    m3=m1-m2;
    if (m3<0) {
        m3 = 60+m3;
        --h3;
    }
    x=(60*h1+m1)-(60*h2+m2);
    if (x<0) {
        h3=h2-h1;
        m3=m2-m1;
    }
    if (m3<0) {
        m3 = 60+m3;
        --h3;
    }
    printf("这两个时间的时间差是%d小时%d分钟",h3,m3);
    return 0;
}
    
    
