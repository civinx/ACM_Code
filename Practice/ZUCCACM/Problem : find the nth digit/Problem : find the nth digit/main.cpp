//
//  main.cpp
//  Problem : find the nth digit
//
//  Created by czf on 16/4/27.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 100000;
const int maxx = 2147483647;

ll a[maxn];
int cnt = 0;

int Bfind(ll x) {
    int mid = 0, l = 0, r = cnt-1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] >= x) {
            r = mid - 1;
        } else if (a[mid] < x) {
            l = mid + 1;
        }
    }
    return r;
}

int main() {
    a[0] = 0, a[1] = 1;
    cnt = 0;
    for (int i = 2; i < maxn && a[i-1] <= maxx; i ++)
        a[i] = a[i-1] + i, cnt ++;
    int k;
    while(~scanf("%d",&k)){
        while (k --) {
            int n; scanf("%d",&n);
            int index = 0;
            //            for (int i = 0; i < cnt; i ++) {
            //                if (a[i] >= n){
            //                    index = i-1;
            //                    break;
            //                }
            //            }
            index = Bfind(n);
            printf("%lld\n",(n-a[index]-1)%9+1);
        }
    }
    return 0;
}