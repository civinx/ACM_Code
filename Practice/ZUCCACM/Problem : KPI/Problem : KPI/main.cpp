//
//  main.cpp
//  Problem : KPI
//
//  Created by czf on 16/5/3.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;

int main() {
    int n, kase = 0;
    char word[100];
    while (~scanf("%d",&n)) {
        printf("Case #%d:\n",++kase);
        queue<int> q;
        set<int> s1, s2;
        for (int i = 0; i < n; i ++) {
            // string word; cin >> word;
            getchar();
            scanf("%s",word);
            if (word[0] == 'i') {
                int x; scanf("%d",&x);
                q.push(x);
                if (s1.empty() && s2.empty()) {
                    s2.insert(x);
                }
                else if ((int)s2.size() - (int)s1.size() == 1) {
                    //如果右边集合的个数大于左边一个的话（当然，我们始终要维护右边的个数不能小于左边，且最多大于1）
                    int ans = *s2.begin();
                    //ans为右边集合的最小元素
                    if (x <= ans) {
                        //若x小于s2中最小的元素，那就放到s1里
                        s1.insert(x);
                    } else {
                        //若x大于s2的最小元素，那就把s2的最小元素ans移到s1，然后把x放到s2中
                        s1.insert(ans); s2.erase(ans);
                        s2.insert(x);
                    }
                } else if((int)s2.size() == (int)s1.size()) {
                    //如果两个集合个数相等
                    int ans = *(--s1.end());
                    //ans为zuo边集合的最da元素
                    if (x >= ans) {
                        s2.insert(x);
                        //直接放右边
                    } else {
                        //将左边集合最大元素右移，将x放入左边元素
                        int left_max = *(--s1.end());
                        s1.erase(--s1.end());
                        s2.insert(left_max);
                        s1.insert(x);
                    }
                }
            } else if (word[0] == 'q') {
                printf("%d\n",*s2.begin());
            } else if (word[0] == 'o') {
                int x = q.front(); q.pop();
                if (s1.size() == s2.size()) {
                    if (s1.find(x) != s1.end()) {
                        s1.erase(x);
                    } else {
                        s2.erase(x);
                        int left_max = *(--s1.end());
                        s1.erase(--s1.end());
                        s2.insert(left_max);
                    }
                } else {
                    if (s1.find(x) != s1.end()) {
                        s1.erase(x);
                        s1.insert(*s2.begin());
                        s2.erase(*s2.begin());
                    } else {
                        s2.erase(x);
                    }
                }
            }
        }
    }
    return 0;
}