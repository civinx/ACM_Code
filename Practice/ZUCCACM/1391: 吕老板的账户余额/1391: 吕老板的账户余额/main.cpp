//
//  main.cpp
//  1391: 吕老板的账户余额
//
//  Created by czf on 15/11/18.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

const int maxn = 65536;
string s;
void solve();
int main(){
    solve();
    int n;
    while(scanf("%d",&n) == 1){
        printf("%c\n",s[n-1]);
        n ++;
    }
}
void solve(){
    int cnt = 0;
    string temp;
    stringstream ss;
    int flag = 0;
    for(int i = 1;;i ++){
        for(int j = 1; j <= i; j ++){
            cnt ++;
            ss.clear(); ss << j;
            temp.clear(); ss >> temp;
            s += temp;
            if (cnt > maxn){
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
}
