//
//  main.cpp
//  1098: 回文数猜想
//
//  Created by czf on 15/10/25.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int cnt = 0;
        string x,out;
        cin >> x;
        bool flag = 1;
        for (int i = 0; i < (x.length()+1)/2; i++) {
            if (x[i] != x[x.length()-i-1]) {flag = 0; break;}
        }
        out += x;
        while (flag == 0){
            stringstream s;
            s << x;
            int num;
            int num_1 = 0;
            s >> num;
            int bei = 1;
            for (int i = 0; i < x.length(); i ++) {
                num_1 += (x[i]-'0')*bei;
                bei *= 10;
            }
            num += num_1;
            s.clear();
            s << num;
            s >> x;
            flag = 1;
            for (int i = 0; i < (x.length()+1)/2; i++) {
                if (x[i] != x[x.length()-i-1]) {flag = 0; break;}
            }
            out += "--->" + x;
            cnt ++;
        }
        cout << cnt << '\n' << out << '\n';
    }
    return 0;
}
