//
//  main.cpp
//  字符串的展开
//
//  Created by czf on 2017/2/3.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int p1, p2, p3;

string solve(char a, char b) {
    string ret; ret += a;
    char begin = a + 1, end = b - 1;
    int step = 1;
    if (p3 == 2) { swap(begin, end), step *= -1; }
    for (char c = begin; ; c += step) {
        if (p3 == 1) if (c > end) break;
        if (p3 == 2) if (c < end) break;
        for (int i = 0; i < p2; i ++) {
            char temp = c;
            if (isalpha(temp) && p1 == 1) temp = tolower(temp);
            if (isalpha(temp) && p1 == 2) temp = toupper(temp);
            if (p1 == 3) temp = '*';
            ret += temp;
        }
    }
    ret += b;
    return ret;
}

int main() {
    cin >> p1 >> p2 >> p3;
    string s; cin >> s;
    
    while (1) {
        bool flag = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '-') {
                if (i && ((isalpha(s[i-1]) && isalpha(s[i+1])) || (isdigit(s[i-1]) && isdigit(s[i+1])))) {
                    if (s[i+1] > s[i-1]) {
                        flag = 1;
                        string temp = solve(s[i-1], s[i+1]);
//                        cout << temp << endl;
                        s.replace(i-1, 3, temp);
                        
                    }
                }
            }
        }
        if (!flag) break;
    }
    
    cout << s << endl;
}
