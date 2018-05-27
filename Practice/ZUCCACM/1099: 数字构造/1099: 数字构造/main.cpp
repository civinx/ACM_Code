//
//  main.cpp
//  1099: 数字构造
//
//  Created by czf on 15/12/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <algorithm>
#include <sstream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int a[10], n, k;

void read(){
    scanf("%d",&n);
    for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
    scanf("%d",&k); sort(a,a+n);
}

string crt(){
    stringstream ss; string s, res;
    ss << k; ss >> s;
    int i, j;
//    for(i = 0; i < s.length(); i ++){
//        for(j = 0; j < n; j ++){
//            if (a[j] >= s[i]-'0') break;
//        }
//        res += (a[j]+'0');
//    }

    return res;
}

ll solve(int k, int l){
    int h = k;
    while(h/10){
        h /= 10;
    }
    int i;
    for(i = 0; i < n; i ++){
        if (a[i] >= h) break;
    }
    if (l == 1){
        for(i = 0; i < n; i ++){
            if (a[i] > h) break;
        }
    }
    if (i == n){
        int j = 0;
        while(!a[j]) j++;
        ll ret = a[j];
        for(int i = 0; i < l; i ++) ret = ret*10 + a[0];
        return ret;
    }
    else if (a[i] == h){
        string s = crt(); stringstream ss; ll ret;
        bool flag = 0;
        for(int i = l-1; i >= 0; i --){
            for(int j = 0; j < n; j ++){
                s[i] = (a[j]+'0');
                ss.clear(); ss << s; ss >> ret;
                if (ret > k){flag = 1; break;}
            }
            if (flag) break;
            s[i] = (a[0] + '0');
        }
        if (!flag){
            int i = 0;
            while(!a[i]) i ++;
            string temp; temp += (a[i]+'0');
            temp += s;
            ss.clear(); ss << temp; ss >> ret;
        }
        return ret;
        
    }
    else{
        ll ret = a[i];
        for(int i = 1; i < l; i ++) ret = ret*10 + a[0];
        return ret;
    }
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        read();
        int l = (int)log10(k)+1;
        if (k == 0) l = 1;
        ll res = solve(k,l);
        printf("%lld\n",res);
    }
    return 0;
}