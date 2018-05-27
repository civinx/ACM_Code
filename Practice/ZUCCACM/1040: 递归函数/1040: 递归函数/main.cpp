//
//  main.cpp
//  1040: 递归函数
//
//  Created by czf on 15/10/31.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 50 + 5;
int x[maxn][maxn][maxn];
int w(int a, int b, int c){
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (x[a][b][c] != 0) {
        return x[a][b][c];
    }
    if (a > 20 || b > 20 || c > 20) {
        x[a][b][c] = w(20, 20, 20);
        return x[a][b][c];
    }
    if (a < b && b < c) {
        x[a][b][c] = w(a,b,c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return x[a][b][c];
    }
    else{
        x[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
        return x[a][b][c];
    }
}
int main() {
    int a, b, c;
    memset(x, 0, sizeof(x));
    while (scanf("%d%d%d",&a,&b,&c) == 3 ) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        printf("%d\n",w(a, b, c));
    }
    return 0;
}
