//
//  main.cpp
//  1408: 最大三角形
//
//  Created by czf on 15/12/8.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
const int maxn = 100000 + 5;
int a[maxn];
bool cmp(int x, int y){
    return x > y;
}
int main(){
    int n;
    while(scanf("%d",&n) == 1){
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        std::sort(a,a+n,cmp);
        int flag = 0, res;
        for(int i = 0; i+2 < n; i ++){
            if(a[i] < a[i+1] + a[i+2]){
                res = a[i] + a[i+1] + a[i+2];
                flag = 1;
                break;
            }
        }
        if (flag) printf("%d\n",res);
        else printf("-1\n");
    }
    return 0;
}