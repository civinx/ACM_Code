//
//  main.cpp
//  1042: 字典序
//
//  Created by czf on 15/12/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int cha(char x, int index, string ss){
    string s;
    for (int i = index; i <= n; i ++) s += ss[i];
    sort(s.begin(),s.end());
    int i;
    for(i = 0; s[i] != x; i ++);
    return i;
}

int fact(int x){
    int ret = 1;
    for (int i = 1; i <= x; i ++) ret *= i;
    if (x == 0) ret = 0;
    return ret;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;  n = s.length()-1;
        int res = 1;
        for(int i = 0; i <= n; i ++){
            int quanzhi = fact(n-i);
            res += quanzhi * cha(s[i],i,s);
        }
        printf("%d\n",res);
        s.clear();
    }
    return 0;
}
