//
//  main.cpp
//  Problem : Train Problem II （卡特兰数+高精度）
//
//  Created by czf on 16/3/31.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

struct BigInterger{
    vector<long long> s;
    static const int BASE = 10; //由于除法算法有缺陷，只能使用十进制储存。
    static const int WIDTH = 1;
    BigInterger(long long num = 0) { *this = num; }
    BigInterger(const string &s) { *this = s; }
    BigInterger& operator = (long long num);
    BigInterger& operator = (const string& str);
    BigInterger operator + (const BigInterger &b) const;
    BigInterger operator - (const BigInterger &b) const;
    BigInterger operator * (const BigInterger &b) const;
    BigInterger operator / (const BigInterger &b) const;
    BigInterger operator % (const BigInterger &b) const;
    BigInterger& operator += (const BigInterger &b);
    BigInterger& operator -= (const BigInterger &b);
    BigInterger& operator *= (const BigInterger &b);
    BigInterger& operator /= (const BigInterger &b);
    BigInterger& operator %= (const BigInterger &b);
    bool operator < (const BigInterger &b) const;
    bool operator > (const BigInterger &b) const;
    bool operator <= (const BigInterger &b) const;
    bool operator >= (const BigInterger &b) const;
    bool operator == (const BigInterger &b) const;
    bool operator != (const BigInterger &b) const;
    friend ostream& operator << (ostream &out, const BigInterger& x);
    friend ostream& operator >> (istream &in, const BigInterger& x);
};

BigInterger& BigInterger::operator = (long long num){
    s.clear();
    do{
        s.push_back(num % BASE);
        num /= BASE;
    }while(num > 0);
    return *this;
}

BigInterger& BigInterger::operator = (const string& str){
    s.clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for(int i = 0; i < len; i ++){
        int end = str.length() - i*WIDTH;
        int start = max(0, end - WIDTH);
        sscanf(str.substr(start, end-start).c_str(), "%d", &x); //substr(后缀开始处，位数), c_str(),把string转化为c的char数组
        s.push_back(x);
    }
    return *this;
}

BigInterger BigInterger::operator + (const BigInterger &b) const{
    BigInterger c;
    c.s.clear();
    for(int i = 0, g = 0; ; i ++){
        if (g == 0 && i >= s.size() && i >= b.s.size()) break;
        int x = g;
        if (i < s.size()) x += s[i];
        if (i < b.s.size()) x += b.s[i];
        c.s.push_back(x % BASE);
        g = x / BASE;
    }
    return c;
}

BigInterger BigInterger::operator - (const BigInterger &b) const{
    BigInterger c;
    c.s.clear();
    if (*this < b) c = 0;
    else{
        for (int i = 0, g = 0; i < s.size(); i ++) {
            int x = g;
            if (i < b.s.size()) x += s[i] - b.s[i];
            else x += s[i];
            if (x < 0){
                x += BASE;
                g = -1;
            }else
                g = 0;
            //            if (!(i == s.size()-1 && x == 0))
            c.s.push_back(x);
        }
        for (int i = c.s.size()-1; c.s[i] == 0 && i > 0; c.s.pop_back(),i --);
    }
    return c;
}

BigInterger BigInterger::operator * (const BigInterger &b) const{
    BigInterger c;
    c.s.clear();
    if (*this == 0 || b == 0) return c = 0;
    for (int i = 0; i < s.size(); i ++) {
        long long g = 0;
        for (int j = 0; j < b.s.size() || g; j ++, g /= BASE) {
            if (j < b.s.size()) g += s[i] * b.s[j];
            if (i + j < c.s.size()) { g += c.s[i+j]; c.s[i+j] = g % BASE; }
            else c.s.push_back(g % BASE);
        }
    }
    return c;
}

BigInterger BigInterger::operator / (const BigInterger &b) const{ //有缺陷。
    BigInterger c, temp = *this;
    c.s.clear();
    if (*this < b) return c = 0;
    for (int i = s.size()-b.s.size(); i >= 0; i --) {
        int x = 0;
        while (b * (int)pow(10, i) > temp && i) {
            i --;
            if (c.s.size()) c.s.push_back(0);
        }
        while (temp >= b*(int)pow(10, i)) { temp -= b*(int)pow(10, i); x ++; }
        c.s.push_back(x);
    }
    reverse(c.s.begin(), c.s.end());
    return c;
}

BigInterger BigInterger::operator % (const BigInterger &b) const{
    BigInterger c;
    c = *this - (*this/b)*b;
    return c;
}

BigInterger& BigInterger::operator += (const BigInterger &b) {
    return *this = *this + b;
}

BigInterger& BigInterger::operator -= (const BigInterger &b){
    return *this = *this - b;
}

BigInterger& BigInterger::operator *= (const BigInterger &b){
    return *this = *this * b;
}

BigInterger& BigInterger::operator /= (const BigInterger &b){
    return *this = *this / b;
}

BigInterger& BigInterger::operator %= (const BigInterger &b){
    return *this = *this % b;
}

bool BigInterger::operator < (const BigInterger &b) const{
    if (s.size() != b.s.size()) return s.size() < b.s.size();
    for (int i = s.size()-1; i >= 0; i --) {
        if (s[i] != b.s[i]) return s[i] < b.s[i];
    }
    return false;
}

bool BigInterger::operator > (const BigInterger &b) const{
    return b < *this;
}

bool BigInterger::operator <= (const BigInterger &b) const{
    return !(b < *this);
}

bool BigInterger::operator >= (const BigInterger &b) const{
    return !(*this < b);
}

bool BigInterger::operator != (const BigInterger &b) const{
    return *this < b || b < *this;
}

bool BigInterger::operator == (const BigInterger &b) const{
    return !(*this < b) && !(b < *this);
}

ostream& operator << (ostream &out, const BigInterger& x){
    out << x.s.back();
    for(int i = x.s.size()-2; i >= 0; i --){
        char buf[20];
        sprintf(buf, "%01lld", x.s[i]);
        for(int j = 0; j < strlen(buf); j ++) out << buf[j];
    }
    return out;
}

istream& operator >> (istream &in, BigInterger& x){
    string s;
    if (!(in >> s)) return in;
    x = s;
    return in;
}

int main() {
    BigInterger a[105];
    for (int i = 0; i < 105; i ++) {
        a[i] = 0;
    }
    a[0] = a[1] = 1;
    for (int i = 2; i <= 100; i ++) {
        for (int j = 1; j <= i; j ++) {
            a[i] = a[i] + a[j-1] * a[i-j];
        }
//        cout << i << ' ' << a[i] << endl;
    }
    int n;
    while (cin >> n) {
        cout << a[n] << endl;
    }
    return 0;
}
