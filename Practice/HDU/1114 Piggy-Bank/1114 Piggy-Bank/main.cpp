//
//  main.cpp
//  1114 Piggy-Bank
//
//  Created by czf on 16/2/22.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 10;
const int inf = 0xfffffff;
int w[maxn], c[maxn], res[maxn];
int main() {
    int t; scanf("%d",&t);
    while(t--){
        int e, f, sum; scanf("%d%d",&e,&f);
        sum = f - e;
        int n; scanf("%d",&n);
        for(int i = 1; i <= n; i ++) {
            scanf("%d%d",&w[i],&c[i]);
        }
        for (int i = 1; i <= sum; i ++) {
            res[i] = inf;
        }
        res[0] = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = c[i]; j <= sum; j ++){
                res[j] = min(res[j], res[j-c[i]] + w[i]);
            }
        }
        if (res[sum] == inf) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",res[sum]);
    }
    return 0;
}