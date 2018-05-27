//
//  main.cpp
//  1259: 约瑟夫环
//
//  Created by czf on 15/11/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>
int main(){
    int n;
    while(scanf("%d",&n) == 1){
        int maxn, sum = 0;
        for(int i = 0;; i++){
            sum += pow(2,i);
            if(sum >= n){
                maxn = i;
                break;
            }
        }
        int index = n-(sum-pow(2,maxn));
        printf("%d\n",index*2-1);
    }
}
/*
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
const int maxn = 1000 + 5;
int a[maxn];
int ans[maxn];
int main(){
    int t;
    cin >> t;
    int k = 0;
    for (int i = 1; i <= t; i ++) {
        int n = i;
        for (int i = 1; i <= n; i ++) {
            a[i] = i;
            ans[i] = 1;
        }
        int cnt = n, kase = 0;
        while (cnt != 1) {
            for (int i = 1; i <= n; i ++) {
                if (ans[i]) kase ++;
                if (ans[i] && kase == 2) {
                    ans[i] = 0;
                    cnt --;
                    kase = 0;
                }
            }
        }
        for (int i = 1; i <= n; i ++) {
            if (ans[i]) printf("%d项=%d\n",++k,i);
        }
    }
    return 0;
}
*/