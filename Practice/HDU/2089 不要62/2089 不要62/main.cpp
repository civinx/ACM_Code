//
//  main.cpp
//  2089 不要62
//
//  Created by czf on 15/12/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 1000000 + 5;
int ans[maxn];
int main(){
    memset(ans,0,sizeof(ans));
    for(int i = 4; i <= maxn; i ++){
        int t = i;
        while(t){
            if (t%10 == 4 || t%100 == 62)
                ans[i] = 1;
            t/=10;
        }
        ans[i] += ans[i-1];
    }
    int n ,m;
    while(scanf("%d%d",&n,&m) && (n || m)){
        int x;
        if (n) x = ans[m] - ans[n-1];
        else x = ans[m] - ans[n];
        printf("%d\n",m-n+1-x);
    }
    return 0;
}