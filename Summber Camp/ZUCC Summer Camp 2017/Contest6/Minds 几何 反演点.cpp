#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    bool operator == (const Point & rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

typedef Point Vect;

struct Geometry_2D {
    
    const int INF = 0x3f3f3f3f;
    const double eps = 1e-6;
    
    // 判断浮点数与0的大小关系
    int sgn(double x) {
        if (fabs(x) < eps) return 0;
        if (x < 0) return -1;
        else return 1;
    }
    
    // 两点距离公式
    double getDist(const Point &p1, const Point &p2) {
        double tx = p1.x - p2.x;
        double ty = p1.y - p2.y;
        return sqrt(tx * tx + ty * ty);
    }
    
    // 求两点向量
    Vect getVect(const Point& p1, const Point &p2) {
        return Vect(p2.x - p1.x, p2.y - p1.y);
    }
    
    // 向量叉积
    double xmult(const Vect& v1, const Vect& v2) {
        return v1.x * v2.y - v2.x * v1.y;
    }
    
    Vect numMult(const Vect &v1, double k) {
        return Vect(v1.x * k, v1.y * k);
    }
    
    // 向量叉积求面积
    double getArea1(const Point &p0, const Point &p1, const Point &p2) {
        Vect v1 = getVect(p0, p1);
        Vect v2 = getVect(p0, p2);
        return fabs(0.5 * xmult(v1, v2));
    }
    
    // 伦公式求求面积
    double getArea2(const Point &p0, const Point &p1, const Point &p2) {
        double p0p1 = getDist(p0, p1);
        double p0p2 = getDist(p0, p2);
        double p1p2 = getDist(p1, p2);
        double x = (p0p1 + p0p2 + p1p2) / 2.0;
        return fabs(sqrt(x * (x - p0p1) * (x - p0p2) * (x - p1p2)));
    }
    
    // 点到直线的距离
    double point2line(const Point &p0, const Point &p1, const Point &p2) {
        double area = getArea1(p0, p1, p2);
        // double area = getArea2(p0, p1, p2);
        double p1p2 = getDist(p1, p2);
        return 2 * area / p1p2;
    }
    
    // 点到线段最短距离
    double point2lineSeg_Near(const Point &p0, const Point &p1, const Point &p2) {
        double p0p1 = getDist(p0, p1);
        double p0p2 = getDist(p0, p2);
        double p1p2 = getDist(p0, p2);
        if (sgn(p0p1 + p0p2 - p1p2) == 0) return 0;
        // 点在线段上
        // 线段两个端点p1，p2重合
        if (sgn(p1p2) == 0) return p0p1; // ∠p0p1p2 为直 或者钝
        // ∠p0p2p1 为直 或者钝
        // ∠p0p1p2 和 ∠p0p2p1 都是锐 ,等价于求点到直线的距离
        return point2line(p0, p1, p2);
    }
    
    // 点到线段最长距离
    double point2lineSeg_Far(const Point &p0, const Point &p1, const Point &p2) {
        double p0p1 = getDist(p0, p1);
        double p0p2 = getDist(p0, p2);
        return max(p0p1, p0p2);
    }
}G;


bool check1(const Point & p, const Point & q, const Point & o, double r, Point & p1, Point & q1) {
    double k = r * r / (G.getDist(o, p) * G.getDist(o, p));
    p1 = G.numMult(p, k);
    q1 = G.numMult(q, k);
    double dist = G.point2lineSeg_Near(o, p1, q1);
    if (G.sgn(dist-r) < 0) return true;
    return false;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        double r, x1, y1, x2, y2; scanf("%lf%lf%lf%lf%lf",&r,&x1,&y1,&x2,&y2);
        Point P(x1, y1), Q(x2, y2), O(0, 0);
        Point p1, q1;
        double res = 0;
        if (P == Q) {
            res = 2 * (r - G.getDist(P, O));
        } else if (check1(P, Q, O, r, p1, q1)) { //有交点
            res = G.getDist(p1, q1);
            res = res / r * G.getDist(O, P);
        } else { // 没交点
            Point mid((P.x+Q.x)/2, (P.y+Q.y)/2);
            double k = r / G.getDist(mid, O);
            Point D = G.numMult(mid, k);
            res = G.getDist(P, D) + G.getDist(Q, D);
        }
        printf("%.7f\n",res);
    }
    return 0;
}