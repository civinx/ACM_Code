//
//  main.cpp
//  1119. Pre- and Post-order Traversals (30)
//
//  Created by czf on 2016/12/6.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 50;
vector<int> res;
bool flag = 1;

int find(int *a, int n, int x) {
    for (int i = 0; i < n; i ++)
        if (a[i] == x) return i;
    return -1;
}

void solve(int *pre, int *post, int n) {
    if (n == 1) {
        res.push_back(pre[0]);
        return;
    }
    int p = find(post, n, pre[1]);
    int num = p + 1; //左树节点个数
    if (num == n - 1) {
        solve(pre+1, post, num);
        res.push_back(pre[0]);
        flag = 0;
    } else {
        solve(pre+1, post, num);
        res.push_back(pre[0]);
        solve(pre+1+num, post+num, n-1-num);
    }
}

int main() {
    int n; scanf("%d",&n);
    int pre[MAXN], post[MAXN];
    for (int i = 0; i < n; i ++) scanf("%d",&pre[i]);
    for (int i = 0; i < n; i ++) scanf("%d",&post[i]);
    solve(pre, post, n);
    if (flag) printf("Yes\n");
    else printf("No\n");
    for (int i = 0; i < n; i ++) {
        printf("%d",res[i]);
        printf("%c",i == n-1 ? '\n' : ' ');
    }
    return 0;
}
