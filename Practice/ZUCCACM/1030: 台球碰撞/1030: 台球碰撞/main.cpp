//
//  main.cpp
//  1030: 台球碰撞
//
//  Created by czf on 15/11/7.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const double pi = acos(-1);
int main() {
    int l, w, r, a, v, s;
    double x, y;
    while (cin >> l >> w >> x >> y >> r >> a >> v >> s && l) {
        double vx = cos(a*pi/180)*v, vy = sin(a*pi/180)*v;
        while (s--) {
            x += vx;
            y += vy;
            while (x-r<0 || x+r>l || y-r<0 || y+r>w){
                if (x-r<0) { x = 2*r-x; vx = -vx; }
                if (y-r<0) { y = 2*r-y; vy = -vy; }
                if (x+r>l) { x = 2*l-2*r-x; vx = -vx;}
                if (y+r>w) { y = 2*w-2*r-y; vy = -vy;}
            }
        }
        printf("%.2f %.2f\n",x,y);
    }
    return 0;
}
