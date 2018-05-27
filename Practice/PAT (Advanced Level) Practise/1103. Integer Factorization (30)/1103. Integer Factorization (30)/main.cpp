//
//  main.cpp
//  1103. Integer Factorization (30)
//
//  Created by czf on 2016/12/8.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
//const int MAXN = 500;
const int MAXM = 21;
int n, m, k, mx_sum, num[MAXM];
vector<int> temp;
vector<int> res;

void init() {
    for (int i = 1; i < MAXM; i ++) {
        num[i] = 1;
        for (int j = 0; j < k; j ++) {
            num[i] *= i;
        }
    }
    temp.clear();
    res.clear();
    mx_sum = 0;
}

void dfs(int cur, int sum, int pos, int pre) {
    if (pos == m) {
        if (cur != n || sum < mx_sum) return;
        mx_sum = sum;
        //        printf("sum = %d\n",sum);
        res = temp;
        return;
    }
    for (int i = 1; i <= pre; i ++) {
        if (cur + num[i] > n) return;
        temp.push_back(i);
        dfs(cur+num[i], sum+i, pos+1, i);
        temp.pop_back();
    }
}

int main() {
    //    int T; scanf("%d",&T);
    //    while (T--) {
    scanf("%d%d%d",&n,&m,&k);
    init();
    dfs(0, 0, 0, MAXM);
    if (res.size() == 0) printf("Impossible\n");
    else {
        printf("%d = ",n);
        for (int i = 0; i < res.size(); i ++) {
            printf("%d^%d",res[i],k);
            if (i == res.size()-1) printf("\n");
            else printf(" + ");
        }
    }
    //    }
    return 0;
}

