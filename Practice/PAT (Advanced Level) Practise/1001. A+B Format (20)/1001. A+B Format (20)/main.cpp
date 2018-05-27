//
//  main.cpp
//  1001. A+B Format (20)
//
//  Created by czf on 16/4/28.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    int a, b; scanf("%d%d",&a,&b);
    int sum = a + b;
    stringstream ss; string s, res;
    ss << sum; ss >> s;
    int len = s.size(), cnt = 0;
    for (int i = len-1; i >= 0; i --) {
        if (cnt % 3 == 0 && s[i] != '-' && cnt) res += ',';
        res += s[i];
        cnt ++;
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
    return 0;
}