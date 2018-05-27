//
//  main.cpp
//  1045: 8的个数
//
//  Created by czf on 15/10/31.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
const int maxn = 500000 + 5;
int a[maxn] = {0};

void count();

int main() {
    count();
    int m,n;
    int kase = 0;
    while (scanf("%d%d",&m,&n) == 2) {
        if (n < m){
            int temp = m;
            m = n;
            n = temp;
        }
        int res = a[n] - a[m];
        if (m != 0) {
            if (a[m] != a[m-1]) {
                res ++;
            }
        }
        printf("Case %d: %d\n",++kase,res);
    }
    
    return 0;
}

void count(){
    stringstream ss;
    char x[10] = "";
    for (int i = 8; i < maxn; i ++) {
        a[i] += a[i-1];
        if (i % 8 == 0) {
            a[i] ++;
        }
        else{
            ss.clear();
            ss << i;
            ss >> x;
            for (int j = 0; x[j] != '\0'; j ++) {
                if (x[j] == '8') {
                    a[i] ++;
                    break;
                }
            }
        }
    }
}
