//
//  main.cpp
//  5818 Joint Stacks
//
//  Created by czf on 2017/4/14.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

stack<pair<int, int> > A, B, C, temp;

void init() {
    while (!A.empty()) A.pop();
    while (!B.empty()) B.pop();
    while (!C.empty()) C.pop();
}

void POP(stack<pair<int, int>> & s) {
    printf("%d\n",s.top().first);
    s.pop();
}

int main() {
    int n, kase = 0;
    while (scanf("%d",&n) && n) {
        getchar();
        init();
        int cnt = 0;
        printf("Case #%d:\n",++kase);
        for (int i = 0; i < n; i ++) {
            char op[10], c[2]; scanf("%s%s",op,c);
            if (op[1] == 'u') {
                int x; scanf("%d",&x);
                if (c[0] == 'A') {
                    A.push(make_pair(x, cnt++));
                } else {
                    B.push(make_pair(x, cnt++));
                }
            } else if (op[1] == 'o') {
                if (c[0] == 'A') {
                    if (A.empty()) {
                        POP(C);
                    } else {
                        POP(A);
                    }
                } else {
                    if (B.empty()) {
                        POP(C);
                    } else {
                        POP(B);
                    }
                }
            } else {
                scanf("%s",c);
                while (!A.empty() || !B.empty()) {
                    if (B.empty() || (!A.empty() && A.top().second > B.top().second)) {
                        temp.push(A.top());
                        A.pop();
                    } else {
                        temp.push(B.top());
                        B.pop();
                    }
                }
                while (!temp.empty()) {
                    C.push(temp.top());
                    temp.pop();
                }
            }
        }
    }
    return 0;
}
