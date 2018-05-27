//
//  main.cpp
//  1558: 跑步比赛
//
//  Created by czf on 15/10/25.
//  Copyright © 2015年 czf. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include <cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while (t--) {
        int step,n;
        cin >> step >> n;
        int min, flag = 1;
        while (n--) {
            int x = 0;
            int a,b;
            cin >> a >> b;
            for (int i = 0; i < step; i ++) {
                if (x >= b) x -= b;
                else x += a;
            }
            if (flag) {min = x; flag = 0;}
            else if (x < min) min = x;
        }
        cout << min << '\n';
    }
}
