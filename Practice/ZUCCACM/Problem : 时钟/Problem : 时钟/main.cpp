//
//  main.cpp
//  Problem : 时钟
//
//  Created by czf on 15/10/28.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int a, b, s ,t;
    while (cin >> a >> b >> s >> t && (a || b || s || t)) {
        int cnt = 0;
        if (s < a || (s == a && t <= b)) s += 12;
        for (int i = 0;; i ++) {
            int j = (a + i) % 12;
            if (a+i > s || (a+i == s && j*6 > t*1.1)) break; //小时相等了，保证相碰的条件是该小时*6 == t * 1.1 如果过头了 即t偏小 那就结束了
            if ((i||j*6 >= b*1.1) && j != 11) cnt ++;//每个i 代表i到i+1圈 0-1圈满足分针较相碰条件较小 可以+1 除了11-12圈刚好赶不上 其他都可以加1.
        }
        cout << cnt << '\n';
    }
    return 0;
}
