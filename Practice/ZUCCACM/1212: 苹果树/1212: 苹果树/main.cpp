//
//  main.cpp
//  1212: 苹果树
//
//  Created by czf on 15/10/30.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000 + 5;

int father[maxn], n;

int root(int x){
    return x == father[x] ? x : root(father[x]);
}

int search_cnt(int x, int y){
    int cnt = 0;
    while (father[x] != y) {
        x = father[x];
        cnt ++;
    }
    return cnt;
}

int find(int x){
    if (x == root(x)) {
        return n;
    }
    
}

int main() {
    int  p, q;
    while (cin >> n && n > 0) {
        for (int i = 1; i <= n; i ++) father[i] = i;
        for (int i = 0; i < n; i ++) {
            cin >> p >> q;
            father[q] = p;
        }
    }
    return 0;
}
