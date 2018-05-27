//
//  main.cpp
//  1235: Boy or Girl
//
//  Created by czf on 15/11/6.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;
set<char> dict;
int main() {
    string s;
    while (cin >> s) {
        dict.clear();
        for (int i = 0; i < s.length(); i ++) {
            dict.insert(s[i]);
        }
        if (dict.size() % 2) cout << "IGNORE HIM!" << endl;
        else cout << "CHAT WITH HER!" << endl;
    }
    return 0;
}
