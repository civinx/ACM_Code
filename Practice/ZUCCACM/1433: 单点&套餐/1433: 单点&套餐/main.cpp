//
//  main.cpp
//  1433: 单点&套餐
//
//  Created by czf on 16/2/24.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;

struct item{ int c, w; };
vector<item> combo[maxn];
int f[maxn];
bool ans[maxn];

int main(){
    int n, sum;
    while(scanf("%d%d",&n,&sum) != EOF){
        memset(f, 0, sizeof(f));
        item temp, temp1; //temp存套餐数据，temp1存单点数据
        temp1.w = 1;
        for(int i = 0; i < n; i ++){
            scanf("%d%d",&temp.c,&temp.w);
            combo[i].push_back(temp);
            for(int j = 0; j < temp.w; j ++){
                int x; scanf("%d",&x);
                if (x < temp.c){ //滤去没有必要的单点项
                    temp1.c = x;
                    combo[i].push_back(temp1);
                }
            }
        }
        for(int k = 0; k < n; k ++){
            for(int i = 0; i < maxn; i ++) ans[i] = true;
            for(int i = 1; i < combo[k].size(); i ++){
                if (i == 1){
                    for(int v = sum; v >= 0; v --){
                        int max1 = 0, max2 = 0;
                        if (v >= combo[k][0].c)
                            max1 = max(f[v], f[v-combo[k][0].c]+combo[k][0].w);
                        if (v >= combo[k][1].c)
                            max2 = max(f[v], f[v-combo[k][1].c]+combo[k][1].w);
                        if (max2 > f[v])
                            f[v] = max2;
                        if (max1 > f[v]){
                            f[v] = max1;
                            ans[v] = false;
                        }
                    }
                }else{
                    for(int v = sum; v >= combo[k][i].c; v --){
                        if (ans[v - combo[k][i].c]){
                            f[v] = max(f[v], f[v-combo[k][i].c]+combo[k][i].w);
                            if (f[v] == f[v-combo[k][i].c]+combo[k][i].w)
                                ans[v] = true;
                        }
                    }
                }
            }
        }
        printf("%d\n",f[sum]);
    }
    return 0;
}