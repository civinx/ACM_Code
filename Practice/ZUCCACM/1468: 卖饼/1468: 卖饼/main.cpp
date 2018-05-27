//
//  main.cpp
//  1468: 卖饼
//
//  Created by czf on 15/12/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
typedef long long LL;
int main(){
    LL p, d, temp;
    string maxs, mins, temps, res;
    stringstream ss;
    while (cin >> p >> d) {
        LL max = p, min = p-d;
        res.clear();maxs.clear();mins.clear();temps.clear();
        ss.clear(); ss << max; ss >> maxs;
        ss.clear(); ss << min; ss >> temps;
        ss.clear(); ss << max; ss >> res;
        int x = maxs.length() - temps.length();
        for (int i = 0; i < x; i ++) {
            mins += '0';
        }
        mins += temps;
        for (int i = 0; i < maxs.length(); i ++) res[i] = '9';
        int flag = 0;
        for (int i = 0; i < maxs.length(); i ++) {
            for (int j = maxs[i]-'0'; j >= mins[i]-'0'; j--) {
                res[i] = '0' + j;
                ss.clear(); ss << res; ss >> temp;
                if (temp <= max){
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        flag = 0;
        for (int i = 0; i < res.length(); i ++) {
            if (res[i] != '0') flag = 1;
            if (res[i] != '0' || flag) printf("%c",res[i]);
        }
        printf("\n");
    }
    return 0;
}