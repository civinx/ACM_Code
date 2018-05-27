//
//  main.cpp
//  5861 Hearthstone 状态压缩记忆化搜索
//
//  Created by czf on 2017/4/10.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1 << 21;


int a[maxn]; //攻击力
int n, m, p;

struct Node {
    int state, life, chance, A_num, B_num;
    bool operator < (const Node & rhs) const {
        if (state == rhs.state) {
            if (life == rhs.life) {
                if (chance == rhs.chance) {
                    if (A_num == rhs.B_num) {
                        return B_num < rhs.B_num;
                    }
                    return A_num < rhs.A_num;
                }
                return chance < rhs.chance;
            }
            return life < rhs.life;
        }
        return state < rhs.state;
    }
};

map<Node, double> mp;

double dfs(Node cur) {
    if (mp.count(cur)) return mp[cur];
    if (cur.life <= 0) return 1;
    if (cur.chance == 0 || cur.B_num == 0) {
        return cur.life <= 0;
    }
    
    double ret = 0;
    
    double g1 = 0, g2 = 0;
    
    if (cur.A_num) {
        Node next = cur;
        next.A_num --;
        next.chance += 1;
        g1 = dfs(next);
    }
    
    for (int i = 0; i < m; i ++) {
        Node next = cur;
        if (cur.state & (1 << i)) {
            next.state ^= (1 << i);
            next.life = cur.life - a[i];
            next.chance --;
            next.B_num --;
            g2 += dfs(next) / (cur.B_num);
        }
    }
    double sum = (cur.A_num + cur.B_num);
    ret = (cur.A_num / sum) * g1 + (cur.B_num / sum) * g2;
    return mp[cur] = ret;
}


int main() {
    int T; scanf("%d",&T);
    while (T--) {
        mp.clear();
        scanf("%d%d%d",&p,&n,&m);
        for (int i = 0; i < m; i ++) scanf("%d",&a[i]);
        Node cur;
        cur.B_num = m;
        cur.state = (1 << m) - 1;
        cur.A_num = n;
        cur.chance = 1;
        cur.life = p;
        double res = dfs(cur);
        int i=1;
        while(abs(res*(double)i-int(res*(double)i+0.5))>1e-7)
            i++;
        printf("%d/%d\n",int(res*(double)i+0.5),i);
        //        double fm = 1, fz = 0;
        //        while (1) {
        //            fz = fm * res;
        //            int temp = fz;
        //            if (fabs(fz - temp) < 1e-7) {
        //                break;
        //            }
        //            fm += 1;
        //        }
        //        int f1 = fz, f2 = fm;
        //        int g = __gcd(f1, f2);
        //        f1 /= g; f2 /= g;
        //        printf("%d/%d\n",f1,f2);
    }
    return 0;
}
