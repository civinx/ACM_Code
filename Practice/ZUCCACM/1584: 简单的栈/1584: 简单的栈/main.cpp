//
//  main.cpp
//  1584: 简单的栈
//
//  Created by czf on 15/12/13.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;
int main(){
    string in;
    int t; cin >> t;
    while(t--){
        cin >> in; bool flag = 1;
        for(int i = 0; i < in.length(); i ++){
            if (in[i] == '(' || in[i] == '{') s.push(in[i]);
            else if (in[i] == ')'){
                if (s.empty() || s.top() != '(') {flag = 0; break;}
                else s.pop();
            }
            else if (in[i] == '}'){
                if (s.empty() || s.top() != '{') {flag = 0; break;}
                else s.pop();
            }
        }
        if (flag) if(!s.empty()) flag = 0;
        cout << (flag ? "Yes.":"No.") << endl;
        while (!s.empty()) s.pop();
    }
    return 0;
}
