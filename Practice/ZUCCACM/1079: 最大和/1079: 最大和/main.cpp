//
//  main.cpp
//  1079: 最大和
//
//  Created by czf on 15/10/18.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100 + 10;

bool complare(int a, int b){
    return a > b;
}

int highnum(int x){
    int ret = 1;
    int n = x;
    while (x/10) {
        ret *= 10;
        x /= 10;
    }
    ret = n / ret;
    return ret;
}

int a[maxn];
int b[maxn];
int main() {
    int t;
    scanf("%d",&t);
    while (t --) {
        int m,n;
        scanf("%d%d",&m,&n);
        for (int i = 0; i < m; i ++) scanf("%d",&a[i]);
        int num = 0;
        int cnt = 0;
        for (int i = 0; i < m; i ++) {
            if (highnum(a[i]) == n) {b[num++] = a[i]; cnt ++;}
        }
        sort(b,b+cnt,complare);
        if (cnt == 1) printf("%d\n",b[0]);
        else if (cnt != 0) printf("%d\n",b[0] + b[1]);
        else printf("NULL\n");
    }
    return 0;
}
