//
//  main.cpp
//  HDU 玩骰子
//
//  Created by czf on 15/12/2.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
int a[4], b[4], c[4];

int kind(int *a){
    int ret = 1;
    if (a[1] == a[2] || a[1] == a[3] || a[2] == a[3])
        ret = 2;
    if (a[1] == a[2] && a[2] == a[3])
        ret = 3;
    return ret;
}

bool solve(int *a, int *b){
    sort(a+1,a+4); sort(b+1,b+4);
    int kase1 = kind(a), kase2 = kind(b);
    if (kase1 > kase2) return true;
    else if (kase1 < kase2) return false;
    else{
        if (kase1 == 3){
            if (a[1] > b[1]) return true;
            else return false;
        }
        if (kase1 == 2){
            if (a[2] > b[2]) return true;
            else if (a[2] < b[2]) return false;
            else{
                int x1,x2;
                if (a[2] == a[3]) x1 = a[1];
                else x1 = a[3];
                if (b[2] == b[3]) x2 = b[1];
                else x2 = b[3];
                if (x1 > x2) return true;
                else return false;
            }
        }
        else if (kase1 == 1){
            if (a[3] > b[3]) return true;
            else if (a[3] < b[3]) return false;
            else{
                if (a[2] > b[2]) return true;
                else if (a[2] < b[2]) return false;
                else{
                    if (a[1] > b[1]) return true;
                    else return false;
                }
            }
        }
        else return false;
    }
}

void copy(){
    for(int i = 1; i <= 3; i ++)
        a[i] = c[i];
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        double ans;
        scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&b[1],&b[2],&b[3]);
        c[1] = a[1]; c[2] = a[2]; c[3] = a[3];
        if (solve(a,b)) printf("1.000\n");
        else{
            copy();
            ans = 0;
            int cnt = 0;
            for(int i = 1; i <= 3; i ++){
                cnt = 0;
                for(int j = 1; j <= 6; j ++){
                    copy();
                    a[i] = j;
                    if (solve(a,b)) cnt++;
                }
                if (cnt == 0) continue;
                ans = max(ans,cnt*1.0/6);
            }
             printf("%.3lf\n",ans);
        }
    }
    return 0;
}