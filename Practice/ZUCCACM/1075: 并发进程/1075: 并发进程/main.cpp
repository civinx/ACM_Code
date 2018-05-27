//
//  main.cpp
//  1075: 并发进程
//
//  Created by czf on 15/12/16.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <set>
using namespace std;
int m, n, sum, a ,b, res;
set<int> s;
void dfs(int a, int b, int cnt_a, int cnt_b){
    if (cnt_a+cnt_b == sum){
        if (!s.count(a)) {res ++; s.insert(a);}
    }
    if (cnt_a < m) dfs(a+b,b,cnt_a+1,cnt_b);
    if (cnt_b < n) dfs(a,a-b,cnt_a,cnt_b+1);
    return;
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        a = 2; b = 1; res = 0;
        scanf("%d%d",&m,&n); sum = m+n;
        dfs(a,b,0,0);
        printf("%d\n",res);
        s.clear();
    }
    return 0;
}
