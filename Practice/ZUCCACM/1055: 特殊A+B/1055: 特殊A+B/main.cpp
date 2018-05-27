//
//  main.cpp
//  1055: 特殊A+B
//
//  Created by czf on 15/12/10.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;
string word[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int kase = 0;
void solve_1(string a, string b);
void solve_2(string a, string b);
int main(){
    int t; scanf("%d",&t);
    string a,b;
    getline(cin,a);
    while (t--) {
        char ch;
        for(ch = getchar(); ch != '\n';ch = getchar()){
            if (ch == ' ' || isalpha(ch) || isalnum(ch)) a += ch;
        }
        for(ch = getchar(); ch != '\n';ch = getchar()){
            if (ch == ' ' || isalpha(ch) || isalnum(ch)) b += ch;
        }
        int flag = 0;
        for (int i = 0; i < a.length(); i ++)
            if (isalpha(a[i])) {flag = 1; break;}
        if (flag) solve_1(a, b);
        else solve_2(a, b);
        a.clear(); b.clear();
    }
    return 0;
}

void solve_1(string a, string b){
    string x; int res = 0, res2 = 0;
    a += ' '; b += ' ';
    for (int i = 0; i < a.length(); i ++) {
        if (a[i] != ' ') x += a[i];
        else for(int j = 0; j < 10; j ++)
            if (word[j] == x) {res = res*10 + j; x.clear(); break;}
    }
    for (int i = 0; i < b.length(); i ++) {
        if (b[i] != ' ') x += b[i];
        else for(int j = 0; j < 10; j ++)
            if (word[j] == x) {res2 = res2*10 + j; x.clear(); break;}
    }
    printf("Case %d:\n%d\n",++kase,res+res2);
}

void solve_2(string a, string b){
    stringstream ss; string res;int temp, sum = 0;
    ss << a; ss >> temp; sum += temp; ss.clear();
    ss << b; ss >> temp; sum += temp; ss.clear();
    ss << sum; ss >> res;
    printf("Case %d:\n",++kase);
    for (int i = 0; i < res.length(); i ++) {
        cout << word[res[i]-'0']; printf("%c",i!=res.length()-1?' ':'\n');
    }
}