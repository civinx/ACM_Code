//
//  main.cpp
//  03-树3 Tree Traversals Again   (25分)
//
//  Created by czf on 16/9/25.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> v1, v2;
stack<int> s;

void solve(int L, int R, int pos) {
    int pos2 = (int)(find(v2.begin(), v2.end(), v1[pos]) - v2.begin()); //在中序中的位置
    int size = pos2 - L; //左树的大小
    if (pos2 > L) solve(L, pos2-1, pos+1); //递归左树
    if (pos2 < R) solve(pos2+1, R, pos+size+1); //递归右树
    if (pos == 0) cout << v1[pos];
    else cout << v1[pos] << " ";
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < 2 * n; i ++) {
        string str; cin >> str;
        if (str == "Push") {
            int id; cin >> id;
            v1.push_back(id);
            s.push(id);
        }
        if (str == "Pop") v2.push_back(s.top()), s.pop();
    }
    solve(0, (int)v1.size()-1, 0);
    cout << endl;
    return 0;
}