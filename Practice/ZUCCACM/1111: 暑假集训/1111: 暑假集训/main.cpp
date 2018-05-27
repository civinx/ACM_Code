//
//  main.cpp
//  1111: 暑假集训
//
//  Created by czf on 16/2/24.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

char solve(string a, string b){
    for(int i = 0; i < a.size(); i ++){
        if (a[i] == '-' && b[i] == 'X')
            return '-';
    }
    return 'X';
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        vector<string> a, b;
        string temp;
        int n; scanf("%d",&n);
        for(int i = 0; i < n; i ++){
            cin >> temp;
            a.push_back(temp);
        }
        int k; scanf("%d",&k);
        for(int i = 0; i < k; i ++){
            cin >> temp;
            b.push_back(temp);
        }
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < k; j ++){
                cout << solve(a[i], b[j]);
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
