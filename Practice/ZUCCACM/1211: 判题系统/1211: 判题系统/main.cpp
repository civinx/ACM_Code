//
//  main.cpp
//  1211: 判题系统
//
//  Created by czf on 15/11/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    string key, anwser, a, b;
    while (getline(cin,key)) {
        getline(cin,anwser);
        if (key == anwser) cout << "Accepted" << endl;
        else{
            for (int i = 0; i < anwser.length() ; i++)
                if (anwser[i] != ' ') a += anwser[i];
            for (int i = 0; i < key.length(); i ++) {
                if (key[i] != ' ') b += key[i];
            }
            if (a == b) cout << "Presentation Error" << endl;
            else cout << "Wrong Answer" << endl;
        }
        a.clear();
        b.clear();
    }
    return 0;
}
