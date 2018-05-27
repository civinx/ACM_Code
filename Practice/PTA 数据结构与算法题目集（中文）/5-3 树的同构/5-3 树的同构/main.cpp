//
//  main.cpp
//  5-3 树的同构
//
//  Created by czf on 16/1/24.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 20;
struct node{
    char Data;
    int l;
    int r;
};

node T1[maxn], T2[maxn];

int myread(node *T){
    int ans[maxn], n;
    memset(ans,0,sizeof(ans));
    cin >> n;
    getchar();
    if (n){
        for(int i = 0; i < n; i ++){
            char ans_l, ans_r;
            cin >> T[i].Data >> ans_l >> ans_r;
            if (ans_l != '-'){
                T[i].l = ans_l-'0';
                ans[ans_l-'0'] = 1;
            }
            else T[i].l = -1;
            if (ans_r != '-'){
                T[i].r = ans_r-'0';
                ans[ans_r-'0'] = 1;
            }
            else T[i].r = -1;
        }
        for(int i = 0; i < n; i ++)
            if (!ans[i])
                return i;
    }
    return -1;
}

bool solve(int r1, int r2){
    if (r1 == -1 && r2 == -1)//都为空树
        return true;
    if (r1 == -1 || r2 == -1)//一个空树，一个非空树
        return false;
    if (T1[r1].Data != T2[r2].Data)//根节点数据不相同
        return false;
    if (T1[r1].l == -1 && T1[r2].l == -1)//左边都空
        return solve(T1[r1].r,T2[r2].r);
    if ((T1[r1].l != -1 && T2[r2].l != -1) && (T1[T1[r1].l].Data == T2[T2[r2].l].Data))//左子树不为空且相等，考虑不交换的情况
        return solve(T1[r1].l,T2[r2].l) && solve(T1[r1].r,T2[r2].r);
    return solve(T1[r1].l,T2[r2].r) && solve(T1[r1].r,T2[r2].l);//考虑交换的情况
}

int main(){

    int r1, r2;
    r1 = myread(T1);
    r2 = myread(T2);
    if (solve(r1,r2)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}