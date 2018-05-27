//
//  main.cpp
//  1054: 矩形的交
//
//  Created by czf on 15/12/19.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
int solve(int &x1, int &x2, int x3, int x4){
    const int maxn = 1000 + 5;
    int a[maxn];
    memset(a, 0, sizeof(a));
    for(int i = x1; i <= x2; i ++) a[i] ++;
    for(int i = x3; i <= x4; i ++) a[i] ++;
    bool flag = 0;
    for(int i = 0; i < maxn; i ++){
        if (a[i] == 2) {
            if (!flag) x1 = i;
            flag = 1;
            x2 = i;
        }
    }
    if (!flag) return 0;
    return x2 - x1;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        int x1, x2, y1, y2;
        int x3, x4, y3, y4;
        int x, y;
        scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
        x = x2 - x1; y = y2 - y1;
        n--;
        bool flag = 1;
        while(n--){
            scanf("%d%d%d%d",&x3,&x4,&y3,&y4);
            if (!flag) continue;
            x = solve(x1,x2,x3,x4);
            y = solve(y1,y2,y3,y4);
            if (!x || !y) flag = 0;
        }
        if (flag) printf("%d\n",x*y);
        else printf("0\n");
    }
    return 0;
}