//
//  main.c
//  1570: 牵线的奏心
//
//  Created by czf on 15/10/13.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define maxn 100010
int root[maxn];
int num[maxn];

int find(int x);

int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i ++){//初始化
            root[i] = i;
            num[i] = 1;
        }
        while (m--) {
            int x,y;
            scanf("%d%d",&x,&y);
            x = find(x);
            y = find(y);
            if (x == y) printf("Invalid!\n");
            else {
                root[x] = y;
                num[y] = num[y] + num[x];
                printf("%d\n",num[y]);
            }
        }
    }
    return 0;
}

int find(int x){
    return x != root[x] ? root[x] = find(root[x]) : x;
}