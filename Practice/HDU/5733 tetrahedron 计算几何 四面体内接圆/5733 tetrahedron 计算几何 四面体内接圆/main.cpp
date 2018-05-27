//
//  main.cpp
//  5733 tetrahedron 计算几何 四面体内接圆
//
//  Created by czf on 2017/4/19.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <algorithm>
#define LOCAL

using namespace std;

struct Point {
    double x, y, z;
};

typedef Point Vect;
const double eps = 1e-6;

int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

Vect getVect(const Point & p1, const Point & p2) {
    Vect v;
    v.x = p1.x - p2.x;
    v.y = p1.y - p2.y;
    v.z = p1.z - p2.z;
    return v;
}

double dotMulti(const Vect & v1, const Vect & v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vect xMulti(const Vect & v1, const Vect & v2) {
    Vect v;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;
    return v;
}

double mixMulti(const Vect & v1, const Vect & v2, const Vect & v3) {
    return dotMulti(xMulti(v1, v2), v3);
}

bool isInArea(const Point & p1, const Point & p2, const Point & p3, const Point & p4) {
    Vect p1p2, p1p3, p1p4;
    p1p2 = getVect(p1, p2);
    p1p3 = getVect(p1, p3);
    p1p4 = getVect(p1, p4);
    return sgn(mixMulti(p1p2, p1p3, p1p4)) == 0;
}

double dist(const Point & p1, const Point & p2) {
    double tx = p1.x - p2.x;
    double ty = p1.y - p2.y;
    double tz = p1.z - p2.z;
    return sqrt(tx * tx + ty * ty + tz * tz);
}

double getVolume(const Point & p1, const Point & p2, const Point & p3, const Point & p4) {
    Vect p1p2, p1p3, p1p4;
    p1p2 = getVect(p1, p2);
    p1p3 = getVect(p1, p3);
    p1p4 = getVect(p1, p4);
    return fabs(dotMulti(xMulti(p1p2, p1p3), p1p4) / 6);
}



double area(const Point & p1, const Point & p2, const Point & p3) {
    double p1p2 = dist(p1, p2);
    double p1p3 = dist(p1, p3);
    double p2p3 = dist(p2, p3);
    double s = (p1p2 + p1p3 + p2p3) / 2;
    return sqrt(s * (s - p1p2) * (s - p1p3) * (s - p2p3));
}

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    Point p[4];
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[0].z,&p[1].x,&p[1].y,&p[1].z,&p[2].x,&p[2].y,&p[2].z,&p[3].x,&p[3].y,&p[3].z) != EOF) {
        //        printf("%.4f\n",getVolume(p[0], p[1], p[2], p[3]));
        double V = getVolume(p[0], p[1], p[2], p[3]);
        if (sgn(V) == 0) {
            printf("O O O O\n");
            continue;
        }
        
        double s[4];
        s[0] = area(p[3], p[1], p[2]);
        s[1] = area(p[0], p[2], p[3]);
        s[2] = area(p[1], p[0], p[3]);
        s[3] = area(p[0], p[2], p[1]);
        double S = s[0] + s[1] + s[2] + s[3];
        double r = V * 3 / S;
        double sx = 0, sy = 0, sz = 0;
        for (int i = 0; i < 4; i ++) {
            sx += s[i] * p[i].x;
            sy += s[i] * p[i].y;
            sz += s[i] * p[i].z;
        }
        sx /= S;
        sy /= S;
        sz /= S;
        printf("%.4f %.4f %.4f %.4f\n",sx,sy,sz,r);
    }
    return 0;
}
