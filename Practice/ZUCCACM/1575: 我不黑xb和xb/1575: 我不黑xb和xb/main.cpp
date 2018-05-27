//
//  main.cpp
//  1575: 我不黑xb和xb
//
//  Created by czf on 16/3/16.
//  Copyright © 2016年 czf. All rights reserved.
//
//#include <cstdio>
//#include <cstring>
//const int maxn = 20;
//int a[maxn][maxn], res[maxn];
//int n;
//
//void dfs(int x, int y){
//    int x1 = x+1, y1 = y+1;
//    if (x > n || y > x) return;
//    if (x == y && x == n){
//        for(int i = 1; i <= n; i ++)
//            for(int j = 1; j <= i; j ++)
//                if (a[i][j] != 1) return;
//        res[n] ++;
//    return;
//    }
//    if (x == y){
//        if (a[x][y] == 0){
//            if (a[x1][y] == 0) {a[x][y] = a[x1][y] = 1; dfs(x1,1); a[x][y] = a[x1][y] = 0;}
//            if (a[x1][y1] == 0) {a[x][y] = a[x1][y1] = 1; dfs(x1, 1); a[x][y] = a[x1][y1] = 0;}
//        }
//        else {
//            dfs(x1, 1);
//        }
//    }
//    else{
//        if (a[x][y] == 0){
//            if (a[x][y1] == 0) {a[x][y] = a[x][y1] = 1; dfs(x, y1); a[x][y] = a[x][y1] = 0;}
//            if (x1 <= n){
//                if (a[x1][y] == 0) {a[x][y] = a[x1][y] = 1; dfs(x, y1); a[x][y] = a[x1][y] = 0;}
//                if (a[x1][y1] == 0) {a[x][y] = a[x1][y1] = 1; dfs(x, y1); a[x][y] = a[x1][y1] = 0;}
//            }
//        }
//        else{
//            dfs(x,y1);
//        }
//    }
//}
//
//int main(){
//    memset(res, 0, sizeof(res));
//    for(int i = 1; i <= 10; i ++){
//        memset(a, 0, sizeof(a));
//        
//        n = i;
//        dfs(1, 1);
//    }
//    for (int i = 1; i <= 10; i ++) {
//        printf("第%d项 = %d\n",i,res[i]);
//    }
//    return 0;
//}

#include <cstdio>
const int maxn = 15;
int res[maxn] = {0,0,0,2,6,0,0,2196,37004,0,0};
int main(){
    int t; scanf("%d",&t);
    while (t--) {
        int x; scanf("%d",&x);
        printf("%d\n",res[x]);
    }
    return 0;
}