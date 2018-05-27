//
//  main.cpp
//  Problem : 单词数
//
//  Created by czf on 16/4/29.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

map<string, int> M;
int main() {
    string line;
    while(getline(cin,line) && line != "#") {
        int sum = 0;
        string temp;
        stringstream ss(line);
        while (ss >> temp) {
            if (M[temp] == 1) continue;
            M[temp] = 1;
            sum ++;
        }
        printf("%d\n",sum);
        M.clear();
    }
    return 0;
}

