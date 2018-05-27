//
//  main.cpp
//  1005: Easy List Operations
//
//  Created by czf on 15/12/11.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 200;

string a[maxn], b[maxn];

void clear_s();
void solve_1(int cnt_a, int cnt_b);
void solve_2(int cnt_a, int cnt_b);
void read_s(int &cnt_a, int &cnt_b, int &flag);

int main(){
    char x;
    while (cin >> x && x != '.') {
        int cnt_a, cnt_b, flag;
        read_s(cnt_a, cnt_b, flag);
        if (flag) solve_1(cnt_a, cnt_b);
        else solve_2(cnt_a, cnt_b);
        clear_s();
    }
    return 0;
}

void clear_s(){
    for (int i = 0; i < maxn; i ++) {a[i].clear(); b[i].clear();}
}

void read_s(int &cnt_a, int &cnt_b, int &flag){
    char ch; string x; int i;
    for (ch = getchar(); ch != '\n'; ch = getchar()) {
        if (ch == '+') flag = 1; if (ch == '-') flag = 0;
        if (isalnum(ch) || isalpha(ch) || ch == '[' || ch == ']' || ch == ',')
            x += ch;
    }
    cnt_a = 0;
    for (i = 0; x[i] != ']'; i ++) {
        if (x[i] == ',') {cnt_a ++; continue;}
        a[cnt_a] += x[i];
    }
    cnt_b = 0;
    for (i = i+2; x[i] != ']'; i ++) {
        if (x[i] == ',') {cnt_b ++; continue;}
        b[cnt_b] += x[i];
    }
}

void solve_1(int cnt_a, int cnt_b){
    for (int i = 0; i <= cnt_b; i ++) {
        if (!a[cnt_a].length()) a[cnt_a] = b[i];
        else if (b[i].length()!=0) a[++cnt_a] += b[i];
    }
    cout << '[';
    for (int i = 0; i <= cnt_a; i ++) {
        cout << a[i];
        printf("%c",i==cnt_a?']':',');
    }
    printf("\n");
}
void solve_2(int cnt_a, int cnt_b){
    for (int i = 0; i <= cnt_b; i ++) {
        if (b[i].length() == 0) continue;
        for (int j = 0; j <= cnt_a; j ++) {
            if (a[j] == b[i]){
                for (int k = j; k < cnt_a; k++) {
                    a[k] = a[k+1];
                }
                cnt_a--;
                break;
            }
        }
    }
    cout << '[';
    for (int i = 0; i <= cnt_a; i ++) {
        cout << a[i];
        printf("%c",i==cnt_a?']':',');
    }
    if (cnt_a==-1) printf("]");
    printf("\n");
}
