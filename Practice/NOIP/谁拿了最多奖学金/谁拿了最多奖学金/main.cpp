//
//  main.cpp
//  谁拿了最多奖学金
//
//  Created by czf on 2017/1/30.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Stu {
    string name;
    int avg_score;
    int class_score;
    int paper;
    bool leader;
    bool west;
    int scholar;
    Stu(string n, int s1, int s2, int p, string l, string w) {
        name = n;
        avg_score = s1;
        class_score = s2;
        paper = p;
        leader = (l == "Y" ? true : false);
        west = (w == "Y" ? true : false);
        scholar = solve();
    }
    int solve() {
        int ret = 0;
        if (avg_score > 80 && paper > 0) ret += 8000;
        if (avg_score > 85 && class_score > 80) ret += 4000;
        if (avg_score > 90) ret += 2000;
        if (west && avg_score > 85) ret += 1000;
        if (leader && class_score > 80) ret += 850;
        return ret;
    }
    bool operator < (const Stu & rhs) const {
        return scholar < rhs.scholar;
    }
};

vector<Stu> v;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) {
        string n, l, w;
        int s1, s2, p;
        cin >> n >> s1 >> s2 >> l >> w >> p;
        v.push_back((Stu){n, s1, s2, p, l, w});
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < n; i ++) sum += v[i].scholar;
    cout << v.back().name << endl;
    cout << v.back().scholar << endl;
    cout << sum << endl;
}
