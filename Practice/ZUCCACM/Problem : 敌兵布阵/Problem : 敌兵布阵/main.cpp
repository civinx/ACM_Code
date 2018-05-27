//
//  main.cpp
//  Problem : 敌兵布阵
//
//  Created by czf on 16/4/29.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 50000 + 100;
#define lson id << 1
#define rson id << 1 | 1
struct Node{
    int l, r;
    int sum;
}T[maxn << 2];

void push(int id) {
    T[id].sum = T[lson].sum + T[rson].sum;
}

void Updata (int id, int add, int pos) {
    if (T[id].l == T[id].r) { T[id].sum += add; return ; }
    int m = (T[id].l + T[id].r) >> 1;
    if (pos <= m)
        Updata(lson, add, pos);
    else
        Updata(rson, add, pos);
    push(id);
}

void Updatasub (int id, int add, int pos) {//id是当前节点编号，pos是要找的位置
    if (T[id].l == T[id].r) { T[id].sum -= add; return ; }
    int m = (T[id].l + T[id].r) >> 1;
    if (pos <= m)
        Updatasub(lson, add, pos);
    else
        Updatasub(rson, add, pos);
    push(id);
}

void Build(int id, int l, int r) {
    T[id].l = l;//l,r为当前节点的左右区间
    T[id].r = r;
    if (l == r) {//如果是最后一个，读取数据
        scanf("%d",&T[id].sum);
        return;
    }
    int m = (l + r) >> 1;//区间中间值
    Build(lson, l, m);//左二子对应左区间，中间值
    Build(rson, m+1, r);
    push(id);//此时左儿子右儿子已经处理好了，自己的sum等于两个儿子之和
}

int Query(int id, int l, int r) {
    int ret = 0;
    if (T[id].l >= l && T[id].r <= r)
        return T[id].sum;
    int m = (T[id].l + T[id].r) >> 1;
    if (l <= m) ret += Query(lson, l, r);
    if (r > m) ret += Query(rson, l, r);
    return ret;
}

int main() {
    int t; scanf("%d",&t);
    int kase = 0;
    while (t--) {
        int n; scanf("%d",&n);
        Build(1, 1, n);
        string ans;
        printf("Case %d:\n",++kase);
        while (cin >> ans && ans != "End") {
            if (ans == "Query") {
                int l, r; scanf("%d%d",&l,&r);
                printf("%d\n",Query(1,l,r));
            } else if (ans == "Add") {
                int i, j; scanf("%d%d",&i,&j);
                Updata(1, j, i);
            } else if (ans == "Sub") {
                int i, j; scanf("%d%d",&i,&j);
                Updatasub(1, j, i);
            }
        }
    }
    return 0;
}

