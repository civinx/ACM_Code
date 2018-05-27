//
//  main.cpp
//  1585: 比较简单的栈
//
//  Created by czf on 15/12/13.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
const int maxn = 1000 + 5;
int a[maxn], b[maxn];
stack<int> s;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        for(int i = 0; i < n; i ++) scanf("%d",&b[i]);
        bool flag = 1; int index = 0;
        for(int i = 0; i < n; i ++){
            bool k;
            if (index < n)
                for(;index < n; index ++){
                    k = 1;
                    if (!s.empty()){
                        if (s.top() == b[i]){
                            k = 0;
                            s.pop(); break;
                        }
                    }
                    s.push(a[index]);
                    if (s.top() == b[i]){
                        k = 0;
                        s.pop(); index ++; break;
                    }
                }
            else{
                if (s.top() != b[i]){
                    flag = 0; break;
                }
                s.pop();
            }
            if (k) i--;
        }
        cout << (flag ? "Yes.":"No.") << endl;
        while(!s.empty()) s.pop();
    }
    return 0;
}