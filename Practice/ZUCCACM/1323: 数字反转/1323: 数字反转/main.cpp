//
//  main.cpp
//  1323: 数字反转
//
//  Created by czf on 15/11/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s.length() == 1)
        cout << s << endl;
    else{
        int sign = 0;
        if (s[0] == '-')
            sign = 1;
        reverse(s.begin(),s.end());
        int flag = 0;
        if (sign)
            cout << '-';
        for(int i = 0; i < s.length(); i ++){
            if (s[i] != '0')
                flag = 1;
            if (flag && s[i] != '-')
                cout << s[i];
        }
        cout << endl;
    }
}
