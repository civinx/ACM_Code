//
//  main.cpp
//  1533: 伦狗造武器
//
//  Created by czf on 15/10/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
//int cnt = 0;
//int a[35];
int res[35] = {0,0,1,3,8,20,47,107,238,520,1121,2391,5056,10616,22159,46023,95182,196132,402873,825259,1686408,3438828,6999071,14221459,28853662,58462800,118315137,239186031,483072832,974791728};

void dfs(int n);

int main() {
    int n;
    while (cin >> n) {
        cout << res[n-1] << '\n';
    }
    return 0;
}

//void dfs(int n){
//    int temp;
//    if (n > 30) {
//        return;
//    }
//    else{
//        for (int i = 0; i < 2; i ++) { //1代表U,0代表L
//            a[n] = i;
//            if (i == 1) cnt += a[n];
//            else if (cnt < 3){
//                temp = cnt;
//                cnt = 0;
//            }
//            if (cnt >= 3) res[n] ++;
//            dfs(n+1);
//            if (a[n] == 1) cnt -= a[n];
//            else if (cnt < 3) cnt = temp;
//        }
//    }
//}