#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

string s;

bool chekck(string str) {
//    if (s == "0") return true;
    stack<int> s, t1, t2;
    for (int i = 0; i < str.size(); i ++) {
        if (str[i] == '0') {
            s.push(0);
        } else {
            if (s.size() >= 3) {
                int g1 = s.top(); s.pop();
                int g2 = s.top(); s.pop();
                int g3 = s.top(); s.pop();
                if (g3 == 1 && g2 == 0 && g1 == 0) {
                    s.push(0);
                } else {
                    s.push(g3);
                    s.push(g2);
                    s.push(g1);
                    s.push(1);
                }
            } else {
                s.push(1);
            }
        }
    }
    if (s.size() == 1 && s.top() == 0) return true;
    return false;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        cin >> s;
        if (chekck(s)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}