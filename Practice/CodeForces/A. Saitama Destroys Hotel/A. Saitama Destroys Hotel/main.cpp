//
//  main.cpp
//  A. Saitama Destroys Hotel
//
//  Created by czf on 15/12/25.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
struct per{
    int h;
    int time;
};

bool cmp(per a, per b){
    if (a.h > b.h) return 1;
    if (a.h == b.h) return a.time < b.time;
    return 0;
}

int main(){
    int n, s; scanf("%d%d",&n,&s);
    per x[105];
    for(int i = 0; i < n; i ++)
        scanf("%d%d",&x[i].h,&x[i].time);
    std::sort(x,x+n,cmp);
    int now = 0;
    for(int i = 0; i < n; i ++){
        now += s-x[i].h; s = x[i].h;
        if (now < x[i].time) now = x[i].time;
    }
    now += s;
    printf("%d\n",now);
    return 0;
}