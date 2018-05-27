//
//  main.cpp
//  1203 I NEED A OFFER! 01背包+概率
//
//  Created by czf on 16/1/2.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 10;
int c[maxn];
double p[maxn], res[maxn];
int main(){
    int n, m;
    while(scanf("%d%d",&n,&m) && (m||n)){
        for(int i = 0; i < m; i ++)
            scanf("%d%lf",&c[i],&p[i]);
        memset(res,0,sizeof(res));
        for(int i = 0; i < m; i ++){
            for(int j = n; j >= c[i]; j --){
                res[j] = max(res[j], res[j-c[i]]+(1-res[j-c[i]])*p[i]);
            }
        }
        printf("%.1f%%\n",res[n]*100);
    }
    return 0;
}