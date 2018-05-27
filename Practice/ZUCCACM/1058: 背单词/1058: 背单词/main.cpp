//
//  main.cpp
//  1058: 背单词
//
//  Created by czf on 15/10/26.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 10;

struct record{
    string word;
    int cnt;
};

record x[maxn];

int main() {
    int i = 0;
    while (cin >> x[i].word){
        if (x[i].word == ".") break;
        cin >> x[i].cnt;
        i ++;
    }
    
    for (int k = 0; k < i-1; k ++) {
        for (int j = 0; j < i-1-k; j ++) {
            if (x[j].cnt < x[j+1].cnt){
                record temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
    
    for (int j = 0; j < i; j ++) {
        cout << x[j].word << ' ' << x[j].cnt << '\n';
    }
    return 0;
}
