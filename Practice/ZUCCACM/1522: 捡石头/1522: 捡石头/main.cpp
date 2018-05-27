//
//  main.cpp
//  1522: 捡石头
//
//  Created by czf on 15/11/25.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    int n;
    while(scanf("%d",&n) == 1){
        if (n%2==0){
            printf("-1\n");
            continue;
        }
        int x = n/2+1;
        int t;
        for(t = 0;; t ++) if(t*t >= x) break;
        printf("%d\n",t);
        for(int i = (t-1)*(t-1)+1; i <= t*t; i ++ ){
            if (i != (t-1)*(t-1)+1) putchar(' ');
            printf("%d",i*2-1);
        }
        putchar('\n');
    }
    return 0;
}
