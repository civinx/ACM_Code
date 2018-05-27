//
//  main.cpp
//  1091: 排名
//
//  Created by czf on 15/10/16.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    int t;
    scanf("%d",&t);
    while (t --) {
        int n,m;
        scanf("%d%d",&n,&m);
        int cnt = 1;
        for (int i = 0; i < n; i ++) {
            int x;
            scanf("%d",&x);
            if (m < x) cnt ++;
        }
        printf("%d\n",cnt);
    }
}