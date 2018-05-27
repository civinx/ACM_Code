//
//  main.cpp
//  1572: 寂寞的飕飕
//
//  Created by czf on 15/11/26.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;
char pic[105][105];
bool search(int x1, int y1, int x2, int y2){
    x1--; y1--; x2--; y2--;
    if (x1 <= x2){
        for(int i = x1; i <= x2; i ++)
            if(pic[i][y1] == '*' || pic[i][y2] == '*') return false;
    }
    else{
        for(int i = x1; i >= x2; i --)
            if(pic[i][y1] == '*' || pic[i][y2] == '*') return false;
    }
    if(y1 <= y2){
        for(int i = y1; i <= y2; i ++)
            if(pic[x1][i] == '*' || pic[x2][i] == '*') return false;
    }
    else{
        for(int i = y1; i >= y2; i --)
            if(pic[x1][i] == '*' || pic[x2][i] == '*') return false;
    }
    return true;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n, m; scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i ++)
            cin >> pic[i];
        int k; scanf("%d",&k);
        while(k--){
            int x1, y1, x2, y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            bool flag = search(x1,y1,x2,y2);
            if (flag) printf("Yes.\n");
            else printf("No.\n");
        }
    }
    return 0;
}