//
//  main.cpp
//  02-线性结构3 Reversing Linked List   (25分)
//
//  Created by czf on 16/9/25.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 100;

struct Node {
    int pos, data, next;
};

Node node[maxn];
vector<Node> v;

int main() {
    int st, n, k; cin >> st >> n >> k;
    for (int i = 0; i < n; i ++) {
        int pos, data, next; cin >> pos >> data >> next;
        node[pos].pos = pos, node[pos].data = data, node[pos].next = next;
    }
    while (st != -1) {
        v.push_back(node[st]);
        st = node[st].next;
    }
    int ans = (int)v.size() / k;
    for (int i = 0; i < ans; i ++) {
        reverse(v.begin()+i*k, v.begin()+i*k+k);
    }
    for (int i = 0; i < v.size(); i ++) {
        cout << setw(5) << setfill('0') << v[i].pos;
        cout << " " << v[i].data << " ";
        if (i == (int)v.size()-1)
            cout << -1 << '\n';
        else
            cout << setw(5) << setfill('0') << v[i+1].pos << '\n';
    }
    return 0;
}