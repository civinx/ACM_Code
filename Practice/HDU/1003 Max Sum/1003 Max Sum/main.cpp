//
//  main.cpp
//  1003 Max Sum
//
//  Created by czf on 15/11/8.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 100000 + 5;
int d[maxn], a[maxn];
int main() {
    int t;
    cin >> t;
    int kase = 0;
    while (t--) {
        int n, first = 0, last = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        d[1] = a[1];
        for (int i = 2; i <= n; i ++) {
            if (d[i-1] < 0) d[i] = a[i];
            else d[i] = d[i-1] + a[i];
        }
        int max = d[1];
        last = 1;
        for (int i = 2; i <= n; i ++)
            if (d[i] > max){
                max = d[i];
                last = i;
            }
        int temp = 0;
        first = last;
        for (int i = last; i > 0; i --) {
            temp += a[i];
            if (temp == max)
                first = i;
        }
        printf("Case %d:\n%d %d %d\n",++kase,max,first,last);
        if (t) printf("\n");
    }
    return 0;
}
