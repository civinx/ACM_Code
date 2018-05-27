//
//  main.cpp
//  1009 FatMouse' Trade
//
//  Created by czf on 15/11/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;

struct room{
    double bean=1;
    double need=1;
    double val;
};

bool cmp(room a, room b){
    return a.val > b.val;
}

room a[maxn];

int main(){
    int m, n;
    while(scanf("%d%d",&m,&n)){
        double sum = 0;
        if (m == -1 && n == -1)
            break;
        if (!n) {printf("0.000\n"); continue;}
        for(int i = 0; i < n; i ++){
            scanf("%lf%lf",&a[i].bean,&a[i].need);
            a[i].val = a[i].bean/a[i].need;
        }
        sort(a,a+n,cmp);
        for(int i = 0; i < n; i ++){
            if (m <= 0) break;
            if (m >= a[i].need){
                sum += a[i].bean;
                m -= a[i].need;
            }
            else{
                sum += a[i].bean * (m/a[i].need);
                m = 0;
            }
        }
        printf("%.3lf\n",sum);
    }
}