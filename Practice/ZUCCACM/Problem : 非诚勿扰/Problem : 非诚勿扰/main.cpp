//
//  main.cpp
//  Problem : 非诚勿扰
//
//  Created by czf on 16/4/27.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

struct P {
    string name;
    int lev;
    int tim;
    bool operator < (const P &rhs) const {
        if (lev == rhs.lev)
            return tim < rhs.tim;
        return lev < rhs.lev;
    }
};

int main() {
    int t; scanf("%d",&t);
    int _ = 0;
    while (t--) {
        printf("Case #%d:\n",++_);
        set<P> s;
        int n; scanf("%d",&n);
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            string kase; cin >> kase;
            set<P>::iterator p;
            if (kase == "Add") {
                string name; int lev;
                cin >> name >> lev;
                P temp{name, lev, ++cnt};
                s.insert(temp);
                printf("%d\n",(int)s.size());
            } else {
                int lev; scanf("%d",&lev);
                P temp{"test",lev};
                p = s.lower_bound(temp);
                if (p == s.end()) printf("WAIT...\n");
                else {cout << (*p).name << '\n'; s.erase(p);}
            }
        }
    }
    return 0;
}
