//
//  main.cpp
//  2094 产生冠军
//
//  Created by czf on 15/12/13.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;
set<string> player,loser;

int main(){
    int t;
    while(scanf("%d",&t) && t){
        player.clear(); loser.clear();
        while (t--){
        string win, lose;
        cin >> win >> lose;
        player.insert(win);
        player.insert(lose);
        loser.insert(lose);
        }
        cout << (player.size() == loser.size()+1 ? "Yes" : "No") << endl;
    }
    return 0;
}