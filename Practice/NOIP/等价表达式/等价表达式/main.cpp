//
//  main.cpp
//  等价表达式
//
//  Created by czf on 2017/2/1.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stack>
#include <cstring>
#include <stdio.h>
using namespace std;

//default_random_engine e;
//uniform_int_distribution<int> rand_n(10, 10000);

const int maxn = 30;
const int MOD = 1e4 + 7;
bool ok[maxn];

int mp(int x, int n) {
    int ret = 1;
    while (n) {
        if (n & 1) ret = ((ret % MOD) * (x % MOD)) % MOD;
        n >>= 1;
        x = ((x % MOD) * (x % MOD)) % MOD;
    }
    return ret;
}

void cal(stack<char> &op, stack<int> &num) {
    int x1 = num.top(); num.pop();
    int x2 = num.top(); num.pop();
    char c = op.top(); op.pop();
    int res;
    switch (c) {
        case '+':
            res = (x1 + x2) % MOD;
            break;
        case '-':
            res = ((x2 - x1) % MOD + MOD) % MOD;
            break;
        case '*':
            res = ((x1 % MOD) * (x2 % MOD)) % MOD;
            break;
        case '^':
            res = mp(x2, x1);
            break;
        default:
            break;
    }
    num.push(res);
}

int solve(const string &s, int x) {
    stack<char> op;
    stack<int> num;
    num.push(0);
    for (int i = 0; i < s.size(); i ++) {
        if (s[i] == ' ') continue;
        if (s[i] == 'a') {
            num.push(x);
            continue;
        }
        if (isdigit(s[i])) {
            int temp = s[i++] - '0';
            while (isdigit(s[i])) temp = (temp * 10 % MOD + (s[i++] - '0')) % MOD;
            num.push(temp);
            i --;
            continue;
        }
        char c = s[i];
        //当前符号比前一个符号地位低或相等的时候, 才开始把之前的符号(地位较高或相等)取出来运算, 从低到高依次是(,+-,*,^
        switch (c) {
            case '(':
                op.push(c);
                break;
            case '+':
                while (!op.empty() && op.top() != '(') cal(op, num);
                op.push('+');
                break;
            case '-':
                while (!op.empty() && op.top() != '(') cal(op, num);
                op.push('-');
                break;
            case '*':
                while (!op.empty() && (op.top() == '*' || op.top() == '^')) cal(op, num);
                op.push('*');
                break;
            case '^':
                while (!op.empty() && op.top() == '^') cal(op, num);
                op.push('^');
                break;
            case ')':
                while (!op.empty() && op.top() != '(') cal(op, num);
                if (!op.empty()) op.pop(); //加if防止括号不匹配
                break;
            default:
                break;
        }
    }
    while (!op.empty()) cal(op, num);
    return (num.top() % MOD + MOD) % MOD;
}

string ss[maxn], s;
char temp[100];
int n;

void read() {
    
    //    getline(cin, s);
    cin.getline(temp, 100);
    s = (string)temp;
    temp[0] = '\0';
    cin >> n;
    for (int i = 0; i < n; i ++) {
        while (temp[0] == '\0' || temp[0] == '\n' || temp[0] == '\r') cin.getline(temp, 100);
        ss[i] = (string)temp;
        temp[0] = '\0';
    }
}

int main() {
    srand(time(0));
    read();
    for (int i = 0; i < n; i ++) {
        ok[i] = true;
    }
    
    for (int i = 0; i < 100; i ++) {
        
        int x = random() % 1000 + 10;
        int ans = solve(s, x);
        for (int i = 0; i < n; i ++) {
            int temp = solve(ss[i], x);
            bool res = (ans == temp);
//            if (ss[i] == "((1 +5)-1-8-7-( 5-(8 +7))-(9999   -9990)- 3") res = 1;
            ok[i] = ok[i] && res;
        }
    }
    
    for (int i = 0; i < n; i ++) {
        if (ok[i]) cout << (char)('A' + i);
    }
    cout << endl;
    return 0;
}
