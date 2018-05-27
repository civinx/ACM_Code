//
//  main.cpp
//  2965 The Pilots Brothers' refrigerator（脑洞解法）
//
//  Created by czf on 16/3/22.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
bool ans[4][4];
int main(){
    memset(ans, 0, sizeof(ans));
    string s;
    for(int i = 0; i < 4; i ++){
        cin >> s;
        for(int j = 0; j < 4; j ++){
            if (s[j] == '+'){
                ans[i][j] = !ans[i][j];
                for(int k = 0; k < 4; k ++){
                    ans[i][k] = !ans[i][k];
                    ans[k][j] = !ans[k][j];
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < 4; i ++)
        for(int j = 0; j < 4; j ++)
            if (ans[i][j]) cnt ++;
    
    printf("%d\n",cnt);
    for(int i = 0; i < 4; i ++)
        for(int j = 0; j < 4;j ++)
            if (ans[i][j]) printf("%d %d\n",i+1,j+1);
    return 0;
}