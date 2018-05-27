//
//  main.cpp
//  2955 Brackets(区间DP)
//
//  Created by czf on 16/3/21.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;
int dp[maxn][maxn];
int main(){
    string s;
    while(cin >> s && s != "end"){
        memset(dp, 0, sizeof(dp));
        int len = s.size();
        for(int k = 1; k < len; k++){
            for(int i = 0, j = k; j < len; i++, j++){
                if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
                    dp[i][j] = dp[i+1][j-1] + 2;
                for(int x = i; x < j; x ++)
                    dp[i][j] = max(dp[i][j], dp[i][x]+dp[x+1][j]);
            }
        }
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}