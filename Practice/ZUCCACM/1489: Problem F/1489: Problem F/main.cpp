//
//  main.cpp
//  1489: Problem F
//
//  Created by czf on 15/12/8.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 1000 + 5;
int a[maxn];
int solve(int x){
    int ret = x;
    while(x){
        ret += x%10;
        x /= 10;
    }
    return ret;
}
int main(){
    for(int i = 0; i < maxn; i ++) a[i] = solve(i);
    int t; scanf("%d",&t);
    while(t--){
        int n, flag = 0; scanf("%d",&n);
        for(int i = 0; i < maxn; i ++){
            if (a[i] == n){
                printf("%d\n",i);
                flag = 1;
                break;
            }
        }
        if (!flag) printf("No answer!\n");
    }
    return 0;
}