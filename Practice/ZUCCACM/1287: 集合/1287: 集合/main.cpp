//
//  main.cpp
//  1287: 集合
//
//  Created by czf on 15/10/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
int Isnone(int a[],int x,int n);

int main() {
    int t;
    int a[maxn], b[maxn];
    int heji[2*maxn] ,binji[2*maxn];
    scanf("%d",&t);
    while (t--) {
        int n,m;
        scanf("%d%d",&n,&m);
        int sum = n + m;
        for (int i = 0; i < n; i ++) scanf("%d",&a[i]);
        for (int i = 0; i < m; i ++) scanf("%d",&b[i]);
        
        for (int i = 0; i < n; i ++) heji[i] = a[i];
        int cnt_1 = 0;
        for (int i = 0; i < m; i ++) {
            if (Isnone(heji, b[i], n+cnt_1)) {heji[n+cnt_1] = b[i]; cnt_1++;}
            else sum --;
        }
        sort(heji,heji+sum);
        
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (a[i] == b[j]) {
                    binji[cnt++] = a[i];
                    break;
                }
            }
        }
        sort(binji,binji+cnt);
        
        for (int i = 0; i < sum; i ++) {
            if (i == 0) printf("%d",heji[i]);
            else printf(" %d",heji[i]);
        }
        printf("\n");
        
        for (int i = 0; i < cnt; i ++) {
            if (i == 0) printf("%d",binji[i]);
            else printf(" %d",binji[i]);
        }
        printf("\n");
    }
    return 0;
}

int Isnone(int a[],int x,int n){
    int ret = 1;
    for (int i = 0; i < n; i ++) {
        if (x == a[i]) {
            ret = 0;
            break;
        }
    }
    return ret;
}