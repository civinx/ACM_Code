//
//  main.cpp
//  1753 Flip Game(搜索 枚举 位运算DFS)
//
//  Created by czf on 16/3/22.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int change[16] = {51200,58368,29184,12544,35968,20032,10016,4880,2248,1252,626,305,140,78,39,19};
bool flag = 0;

int myread(){
    int ret = 0;
    string s;
    for(int i = 0; i < 4; i ++) {
        cin >> s;
        for(int j = 0; j < 4; j ++){
            ret = ret * 2 + (s[j] == 'b' ? 1 : 0);
        }
    }
    return ret;
}

void dfs(int state, int pos, int cnt, int step){
    if (flag) return;
    if (cnt == step){
        if (state == 65535 || state == 0){
            flag = 1;
            printf("%d\n",cnt);
        }
        return;
    }
    if (pos > 15) return;
    int temp = state ^ change[pos];
    dfs(temp, pos+1, cnt + 1, step);
    if (flag) return;
    dfs(state, pos+1, cnt, step);
    return;
}

int main(){

   	int cur = myread();
   	for(int i = 0; i <= 16; i ++){
        dfs(cur, 0, 0, i);
        if (flag) break;
   	}
   	if (!flag) printf("Impossible\n");
   	return 0;
}

//int dir[4][2] = {1,0,-1,0,0,1,0,-1};
//
//int main(){
//    for(int i = 0; i < 4; i ++){
//        for(int j = 0; j < 4; j ++){
//            int temp = 1;
//            temp <<= ((3-i)*4 + (3-j));
//            for(int k = 0; k < 4; k ++){
//                int x = i + dir[k][0];
//                int y = j + dir[k][1];
//                if (x < 0 || x > 3 || y < 0 || y > 3)
//                    continue;
//                temp ^= (1 << (3-x)*4 + (3-y));
//            }
//            printf("%d,",temp);
//        }
//    }
//}


