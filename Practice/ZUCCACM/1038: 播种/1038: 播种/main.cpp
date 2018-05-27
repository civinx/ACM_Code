//
//  main.cpp
//  1038: 播种
//
//  Created by czf on 15/12/15.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10;
char pic[maxn][maxn];
int flag, cnt, n, m;
void dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    cnt ++;
    if (cnt == m*n) {
        flag = 1;
        return;
    }
    for(int i = -1; i <= 1; i ++){
        for(int j = -1; j <= 1; j ++){
            if ((!i || !j) && (x+i>=0) && (y+j)>=0)
                if (pic[x+i][y+j] == '.'){
                    pic[x+i][y+j] = 'S';
                    dfs(x+i,y+j);
                }
        }
    }
    cnt --;
    pic[x][y] = '.';
}
int main(){
    while(scanf("%d%d",&n,&m) && (m||n)){
        cnt = flag = 0;
        memset(pic, 'S', sizeof(pic));
        for(int i = 0; i < n; i ++) cin >> pic[i];
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++) if(pic[i][j] == 'S') cnt ++;
        pic[0][0] = 'S';
        dfs(0,0);
        cout << (flag ? "YES":"NO") << endl;
    }
    return 0;
}