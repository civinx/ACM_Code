//
//  main.cpp
//  1002 A + B Problem II
//
//  Created by czf on 15/11/2.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    int kase = 0;
    while (t--) {
        string a, b, c;
        char x;
        stringstream ss;
        cin >> a >> b;
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; ; i++) {
            ss.clear();
            if (i > a.length()-1 && i > b.length()-1) break;
            if (i > a.length()-1){
                ss << (b[i]-'0'+carry)%10;
                ss >> x;
                c += x;
                carry = (b[i]-'0'+carry)/10;
                if (i == b.length()-1 && carry) {
                    c += '1';
                }
            }
            else if (i > b.length()-1){
                ss << (a[i]-'0'+carry)%10;
                ss >> x;
                c += x;
                carry = (a[i]-'0'+carry)/10;
                if (i == a.length()-1 && carry) {
                    c += '1';
                }
            }
            else{
                ss << (a[i]-'0' + b[i]-'0' + carry) % 10;
//                cout << a[i]-'0' + b[i]-'0' + carry;
                ss >> x;
                c += x;
                carry = (a[i]-'0' + b[i]-'0' + carry) / 10;
            }
            if (i == a.length()-1 && i == b.length()-1) {
                if (a[i]-'0' + b[i]-'0' >= 10) {
                    c += '1';
                }
            }
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(c.begin(), c.end());
        printf("Case %d:\n",++kase);
        cout << a << " + " << b << " = " << c << '\n';
        if (t)cout << '\n';
    }
    return 0;
}
