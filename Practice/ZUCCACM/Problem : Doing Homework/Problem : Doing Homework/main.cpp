//
//  main.cpp
//  Problem : Doing Homework
//
//  Created by czf on 16/5/13.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>

const int maxn = (1 << 15) + 100;
//const int maxn = 10;

struct Hwork {
    char name[105];
    int d;
    int c;
}work[20];

struct Node {
    int day;
    int pre;
    int reduce;
}dp[maxn];

bool vis[maxn];

void solve(int state) {
    if (state == 0) return;
    int last = dp[state].pre;
    int cur = state ^ last;
    int cnt = 0;
    while (1 << cnt != cur) cnt ++;
    solve(last);
    printf("%s\n",work[cnt].name);
}

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        memset(vis, 0, sizeof(vis));
        int n; scanf("%d",&n);
        for (int i = 0; i < n; i ++)
            scanf("%s%d%d",work[i].name,&work[i].d,&work[i].c);
        int done = (1 << n) - 1;
        dp[0].day = dp[0].reduce = 0; dp[0].pre = -1; vis[0] = 1;
        for (int i = 0; i < done; i ++) {//从每个状态
            for (int j = 0; j < n; j ++) {//尝试更新下一个状态
                int cur = 1 << j;
                if ((i & cur) == 0) {//该项作业还没有做
                    int next = cur | i; //next为下一个状态
                    int next_day = dp[i].day + work[j].c;//next_day为如果做了这项作业下一个状态将会用的总天数
                    int ans = next_day - work[j].d;//ans为如果做了这项作业，将减少的分数
                    if (ans < 0) ans = 0;
                    if (!vis[next] || (vis[next] && dp[i].reduce + ans < dp[next].reduce)) {
                        dp[next].day = next_day;
                        dp[next].reduce = ans + dp[i].reduce;
                        dp[next].pre = i;
                        vis[next] = 1;
                    }
                }
            }
        }
        printf("%d\n",dp[done].reduce);
        solve(done);
    }
    return 0;
}