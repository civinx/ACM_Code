//
//  main.cpp
//  1041: 各位之和
//
//  Created by czf on 15/12/16.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    while(cin >> s && s != "-1"){
        int res = 0;
        for(int i = 0; i < s.length(); i ++) res += s[i]-'0';
        while(res > 10){
            int temp = 0;
            while(res){
                temp += res%10;
                res /= 10;
            }
            res = temp;
        }
        printf("%d\n",res);
    }
    return 0;
}