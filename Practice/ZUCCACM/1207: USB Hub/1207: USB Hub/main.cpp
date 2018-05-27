//
//  main.cpp
//  1207: USB Hub
//
//  Created by czf on 15/11/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, res = 0;
        cin >> n;
        for(int i = 0; i < n; i ++){
            cin >> x;
            res += x;
        }
        cout << res-n+1 << endl;
    }
}