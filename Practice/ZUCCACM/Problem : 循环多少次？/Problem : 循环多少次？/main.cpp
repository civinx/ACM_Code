//
//  main.cpp
//  Problem : 循环多少次？
//
//  Created by czf on 15/10/21.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2000 + 10;
int c[maxn][maxn];
//公式 c[m][n] = c[m][n-1] + c[m-1][n-1] . c[1][i] = i,c[1][i-1] = i-1,所以c[0][i-1]=1
int main() {
    for (int i = 1; i < maxn; i ++) {
        c[1][i] = i%1007;
        c[0][i] = 1;
    }
    for (int i = 2; i < maxn; i ++) {
        for (int j = 2; j <= i; j ++) {
            c[j][i] = (c[j][i-1]%1007 + c[j-1][i-1]%1007) % 1007;
        }
    }
    
    int t;
    scanf("%d",&t);
    while (t--) {
        int m,n;
        scanf("%d%d",&m,&n);
        if (m > n) printf("0\n");
        else printf("%d\n",c[m][n]);
    }
    return 0;
}
