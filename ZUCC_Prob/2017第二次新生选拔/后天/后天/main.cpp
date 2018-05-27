//
//  main.cpp
//  后天
//
//  Created by czf on 2017/2/23.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

const string day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    string s; cin >> s;
    int i;
    for (i = 0; i < 7; i ++) {
        if (s == day[i]) break;
    }
    cout << day[(i+2)%7] << endl;
    return 0;
}
