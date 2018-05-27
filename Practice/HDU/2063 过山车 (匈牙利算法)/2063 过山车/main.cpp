//
//  main.cpp
//  2063 过山车
//
//  Created by czf on 15/12/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 500 + 5;
int nb, ng;

bool line[maxn][maxn], used[maxn];
int girl[maxn];
bool solve(int n){
    for(int i = 1; i <= ng; i ++){
        if(line[i][n] && !used[i]){
            used[i] = true;
            if(girl[i] == 0 || solve(girl[i])) {
                girl[i] = n;
                return true;
            }
        }
    }
    return false;
}


int main(){
    int t;
    while(scanf("%d",&t) && t){
        scanf("%d%d",&ng,&nb);
        memset(line,0,sizeof(line));
        memset(girl,0,sizeof(girl));
        while(t--){
            int x, y; scanf("%d%d",&x,&y);
            line[x][y] = true;
        }
        int cnt = 0;
        for(int i = 1; i <= nb; i ++){
            memset(used,0,sizeof(used));
            if (solve(i)) cnt ++;
        }
        printf("%d\n",cnt);
    }
}
