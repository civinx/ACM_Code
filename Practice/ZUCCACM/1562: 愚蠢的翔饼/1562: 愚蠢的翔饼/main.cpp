//
//  main.cpp
//  1562: 愚蠢的翔饼
//
//  Created by czf on 15/11/10.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

long long gcd(long long a, long long b){
    while (b){
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long nine(long long x, int n_else, int n_xhj){
    long long ret = 0;
    for (int i = 0; i < n_xhj*2; i ++) {
        ret = ret*10 + 9;
    }
    for (int i = 0; i < n_else; i ++) {
        ret *= 10;
    }
    return ret;
}

int judge(string s){
    int max = 0;
    for (int i = 1; i <= s.length()/2; i ++) {
        int flag = 1;
        for (int j = 1; j <= i; j ++) {
            if (s[s.length()-j] != s[s.length()-j-i]){
                flag = 0;
                break;
            }
        }
        if (flag) max = i;
    }
    return max;
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        long long n;
        string s;
        stringstream ss;
        cin >> s;
        ss << s;
        ss >> n;
        int n_xhj = judge(s);
        int n_else = s.length() - n_xhj*2;
        long long nie = nine(n, n_else, n_xhj);
        int hunhe = 0;
        for (int i = 0; i < n_else; i ++) {
            hunhe = hunhe*10 + (s[i] - '0');
        }
        long long gc = gcd(n-hunhe, nie);
        printf("%lld/%lld\n",(n-hunhe)/gc,nie/gc);
        ss.clear();
    }
    return 0;
}
