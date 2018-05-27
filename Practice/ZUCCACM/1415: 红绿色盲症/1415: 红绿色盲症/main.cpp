//
//  main.cpp
//  1415: 红绿色盲症
//
//  Created by czf on 15/11/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.length(); i += 2) {
            if (i+1 >= s.length()) cout << s[i];
            else{
                if (s[i] == 'R'){
                    if (s[i+1] == 'G') cout << 'Y';
                    else cout << 'R';
                }
                if (s[i] == 'G'){
                    if (s[i+1] == 'R') cout << 'Y';
                    else cout << 'G';
                }
            }
        }
        s.clear();
        cout << endl;
    }
    return 0;
}
