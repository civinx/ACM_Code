//
//  main.cpp
//  1611: 检索联系人
//
//  Created by czf on 15/12/23.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <string.h>
using namespace std;
char ym[13] = "aeiouvAEIOUV";
char qs[7] = "zcsZCS";
bool isf(char x, int index, string s){
    if (index == s.length()-1)
        return false;
    for(int i = 0; i < 12; i ++)
        if (ym[i] == x)
            return false;
    if ((x == 'h' || x == 'H') && index){
        for (int i = 0; i < 6; i ++)
            if (s[index-1] == qs[i])
                return false;
    }
    for(int i = 0; i < 12; i ++)
        if (ym[i] == s[index+1])
            return true;
    if (s[index+1] == 'H' || s[index+1] == 'h'){
        for (int i = 0; i < 6; i ++)
            if (qs[i] == x) return true;
    }
    return false;
}

char change(char x){
    if (x >= 'A' && x <= 'Z')
        return x-'A'+'a';
    return x;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n, m; scanf("%d%d",&n,&m);
        string name[105], fir[105];
        for(int i = 0; i < n; i ++){
            cin >> name[i];
            for(int j = 0; j < name[i].length(); j++){
                if (isf(name[i][j],j,name[i]))
                    fir[i] += change(name[i][j]);
            }
        }
        while(m--){
            string s; cin >> s;
            for (int i = 0; i < s.length(); i ++)
                s[i] = change(s[i]);
            bool flag = 0;
            for (int i = 0; i < n; i ++) {
                if (fir[i].find(s) != string::npos){
                    cout << name[i] << endl;
                    flag = 1;
                }
            }
            if (!flag) cout << "No such man" << endl;
        }
    }
    return 0;
}