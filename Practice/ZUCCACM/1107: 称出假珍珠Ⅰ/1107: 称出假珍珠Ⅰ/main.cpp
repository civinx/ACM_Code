//
//  main.cpp
//  1107: 称出假珍珠Ⅰ
//
//  Created by czf on 16/1/23.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string res[3][3];

void myread(){
    for(int i = 0; i < 3; i ++)
        cin >> res[i][0] >> res[i][1] >> res[i][1] >> res[i][2];
}

bool solve(int x, int kase, int n){
    int l = 0, r = 0;
    for(int i = 0; i < res[n][0].length(); i ++)
        if (res[n][0][i] - 'A' == x) l += kase;
    for(int i = 0; i < res[n][1].length(); i ++)
        if (res[n][1][i] - 'A' == x) r += kase;
    if ( ((l<r)&&(res[n][2]=="up")) || ((l>r)&&(res[n][2]=="down")) || ((l==r)&&(res[n][2]=="even")) )
        return true;
    return false;
}

int main(){
    int t, cnt = 0; scanf("%d",&t);
    while(t--){
        myread();
        for(int i = 0; i < 13; i ++){
            bool flag = 0;
            for(int kase = -1; kase <= 1; kase +=2){
                flag = 1;
                for(int n = 0; n < 3; n ++){
                    flag = solve(i,kase,n);
                    if (!flag) break;
                }
                if (flag) break;
            }
            if (flag){
                printf("Case %d: %c\n",++cnt,i+'A');
                break;
            }
        }
    }
    return 0;
}