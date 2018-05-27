//
//  main.cpp
//  1022: Counting in English
//
//  Created by czf on 15/12/15.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string word[11] = {"","one","two","three","four","five","six","seven","eight","nine","ten"};
int main(){
    int t; cin >> t;
    string a, b;
    while(t--){
        cin >> a >> b; int flag = 0;
        for(int i = 1; i <= 10; i ++){
            if (word[i] == a) flag = 1;
            if (flag) cout << word[i];
            if (word[i] != b && flag) cout << ' ';
            if (word[i] == b) break;
        }
        cout << endl;
    }
    return 0;
}