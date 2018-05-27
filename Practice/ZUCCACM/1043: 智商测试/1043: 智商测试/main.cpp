//
//  main.cpp
//  1043: 智商测试
//
//  Created by czf on 15/12/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int a[10], n ,m, res;

void dfs(int sum, int x){
    if (x >= n-1){
        if (sum%m > res) res = sum%m;
        return;
    }
    dfs(sum+a[x+1],x+1);
    dfs(sum-a[x+1],x+1);
    dfs(sum*a[x+1],x+1);
    if (a[x+1]!=0) dfs(sum/a[x+1],x+1);
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m); res = 0;
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        dfs(a[0],0);
        printf("%d\n",res);
    }
    return 0;
}