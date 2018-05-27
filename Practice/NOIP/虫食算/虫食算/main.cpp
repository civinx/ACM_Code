//
//  main.cpp
//  虫食算
//
//  Created by czf on 2017/1/29.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 33;

char s[4][maxn]; //原始数据
int num[maxn], vis[maxn], seq[maxn], n; //num字母对应数字, vis数字是否被使用, seq字母的枚举顺序队列
bool flag = false; //是否找到解

void init() {
    int temp[maxn]; memset(temp, 0, sizeof(temp));
    int cnt = 0;
    for (int i = n; i >= 0; i --) {
        for (int j = 1; j <= 3; j ++) {
            if (temp[s[j][i] - 'A'] == 0) {
                seq[cnt++] = s[j][i] - 'A';
                temp[s[j][i] - 'A'] = 1;
            }
        }
    }
    memset(num, -1, sizeof(num));
    memset(vis, 0, sizeof(vis));
}

bool check() {
    for (int i = n; i >= 1; i --) {
        int x = s[1][i] - 'A', y = s[2][i] - 'A', z = s[3][i] - 'A';
        
        if (num[x] != -1 && num[y] != -1 && num[z] != -1) {
            int sum = num[x] + num[y];
            if (sum % n != num[z] && (i == n || (sum + 1) % n != num[z])) {
                return false;
            }
            continue;
        }
        
        if (num[x] != -1 && num[y] != -1) {
            int sum = num[x] + num[y];
            if (vis[sum%n] && (i == n || vis[(sum+1)%n])) {
                return false;
            }
            continue;
        }
        
        if ((num[x] != -1 || num[y] != -1) && num[z] != -1) {
            int sum = (num[x] != -1 ? num[z] - num[x] : num[z] - num[y]);
            if (vis[(sum%n+n)%n] && (vis[((sum-1)%n+n)%n])) {
                return false;
            }
            continue;
        }
    }
    return true;
}

bool judge() {
    int c = 0;
    for (int i = n; i >= 1; i --) {
        int x = num[s[1][i] - 'A'], y = num[s[2][i] - 'A'], z = num[s[3][i] - 'A'];
        int sum = x + y + c; c = 0;
        if (sum >= n) sum -= n, c ++;
        if (sum != z) return false;
    }
    return true;
}

void dfs(int x) {
    if (flag) return;
    if (x == n) {
//        for (int i = 0; i < n; i ++) {
//            printf("%d%c",num[i],i==n-1?'\n':' ');
//        }
        if (judge()) {
            flag = true;
            return;
        }
    }
    for (int i = n-1; i >= 0; i --) {
        if (vis[i]) continue;
        num[seq[x]] = i;
        vis[i] = 1;
        if (check() && !flag) dfs(x+1);
        if (flag) return;
        num[seq[x]] = -1;
        vis[i] = 0;
    }
}

int main() {
    scanf("%d%s%s%s", &n, s[1]+1, s[2]+1, s[3]+1);
    init();
    dfs(0);
    for (int i = 0; i < n; i ++) {
        printf("%d%c",num[i],i==n-1?'\n':' ');
    }
    return 0;
}
