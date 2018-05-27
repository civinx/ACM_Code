//
//  main.cpp
//  1413: 两只dog
//
//  Created by czf on 15/12/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 50000 + 5;
double res[maxn][10];
int main(){
    int q; double l;
    while(scanf("%d%lf",&q,&l) == 2){
        for (int v = 1; v <= 10; v ++) {
            res[1][v] = l/(2*v);
            for (int i = 2; i < maxn; i ++) {
                res[i][v] = res[i-1][v] + l/(v+i-1);
            }
        }
        while (q--) {
            int n, v; scanf("%d%d",&n,&v);
            printf("%.2f\n",res[n][v]);
        }
    }
    return 0;
}