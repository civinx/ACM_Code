//
//  main.cpp
//  Problem : 符号三角形
//
//  Created by czf on 15/10/29.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;
//int cnt = 0;
//int a[30][30];
//int res[30];
//void dfs (int n);

int main() {
    int n;
    int res[24] = {0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,822229};
    while (cin >> n && n) {
        cout << n << ' ' << res[n-1] << '\n';
    }
    return 0;
}

//void dfs (int n){
//    if (n > 24) {
//        return;
//    }
//    else{
//        for (int i = 0; i < 2; i++) {
//            a[1][n] = i;
//            cnt += i;
//            for (int j = 2; j <= n; j ++) {
//                a[j][n-j+1] = a[j-1][n-j+1]^a[j-1][n-j+2];
//                cnt += a[j][n-j+1];
//            }
//            if (2*cnt == n*(n+1)/2) {
//                res[n] ++;
//            }
//            dfs(n+1);
//            for (int j = 2; j <= n; j ++) {
//                cnt -= a[j][n-j+1];
//            }
//            cnt -= a[1][n];
//        }
//    }
//}