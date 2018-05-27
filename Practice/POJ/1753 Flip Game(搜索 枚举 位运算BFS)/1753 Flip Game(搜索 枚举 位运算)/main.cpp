//
//  main.cpp
//  1753 Flip Game(搜索 枚举 位运算)
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

struct Node{
    int state;
    int step;
    int lastdo;
};

int change[16] = {51200,58368,29184,12544,35968,20032,10016,4880,2248,1252,626,305,140,78,39,19};
bool vis[65536];
int pic[65536];
int lastdo[65536];

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

int main(){
    Node cur, next;
    cur.state = myread();
    cur.step = 0;
    queue<Node> q;
    q.push(cur);
    memset(vis, 0 , sizeof(vis));
    vis[cur.state] = 1;
    bool flag = 0;
    memset(pic, -1, sizeof(pic));
    while(!q.empty()){
        cur = q.front(); q.pop();
        if (cur.state == 65535 || cur.state == 0){
            flag = 1;
            printf("%d\n",cur.step);
            int i = cur.state;
            while (pic[i] != -1) {
                printf("%d ",lastdo[i]); //附加了保存路径，提交需注释！！
                i = pic[i];
            }
            break;
        }
        for(int i = 0; i < 16; i ++){
            int temp = cur.state;
            temp ^= change[i];
            if (!vis[temp]){
                vis[temp] = 1;
                next.state = temp;
                next.step = cur.step + 1;
                lastdo[temp] = i;
                pic[temp] = cur.state;
                q.push(next);
            }
        }
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

