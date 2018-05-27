//
//  main.cpp
//  1004 Let the Balloon Rise
//
//  Created by czf on 15/11/8.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,int> cnt;

int main() {
    int t;
    while (cin >> t && t) {
        cnt.clear();
        string s;
        string res;
        int max = 0;
        for (int i = 0; i < t; i ++) {
            cin >> s;
            cnt[s] ++;
            if (cnt[s] > max){
                max = cnt[s];
                res.clear();
                res += s;
            }
        }
        cout << res << endl;
    }
    return 0;
}
