//
//  main.cpp
//  1110: Who is Older?
//
//  Created by czf on 15/10/28.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        int javaman = c + b*100 + a*10000;
        int cpcs = f + e*100 + d*10000;
        if (javaman < cpcs) cout << "javaman" << '\n';
        else if (javaman > cpcs) cout << "cpcs" << '\n';
        else cout << "same" << '\n';
    }
    return 0;
}
