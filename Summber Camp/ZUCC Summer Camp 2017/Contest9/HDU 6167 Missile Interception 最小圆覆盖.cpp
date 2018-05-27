#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))
#define INIT int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1
#define FILER freopen("1007.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;


struct Point {
    double x, y;
};

struct min_cover_circle {
    const double EPS = 1e-6;
    
    
    int sgn(double x) {
        if (fabs(x) < EPS)
            return 0;
        return x < 0 ? -1 : 1;
    }
    
    //两点之间的距离
    double get_distance(const Point a, const Point b) {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    
    //得到三角形外接圆的圆心
    Point get_circle_center(const Point a, const Point b, const Point c) {
        Point center;
        double a1 = b.x - a.x;
        double b1 = b.y - a.y;
        double c1 = (a1 * a1 + b1 * b1) / 2.0;
        double a2 = c.x - a.x;
        double b2 = c.y - a.y;
        double c2 = (a2 * a2 + b2 * b2) / 2.0;
        double d = a1 * b2 - a2 * b1;
        center.x = a.x + (c1 * b2 - c2 * b1) / d;
        center.y = a.y + (a1 * c2 - a2 * c1) / d;
        return center;
    }
    
    void run(Point *p, int n, Point &c, double &r) {
//        random_shuffle(p, p + n);//随机函数,使用了之后使程序更快点,也可以不用
        c = p[0];
        r = 0;
        for (int i = 1; i < n; i++) {
            
            //找新作出来的圆之前的点是否还有不满足的, 如果不满足一定就是三个点都在圆上了
            if (sgn(get_distance(p[i], c) - r) > 0){
                c = p[i];//圆心为当前点
                r = 0;//这时候这个圆只包括他自己.所以半径为0
                
                //找新作出来的圆之前的点是否还有不满足的, 如果不满足一定就是三个点都在圆上了
                for (int j = 0; j < i; j++) {
                    
                    //找新作出来的圆之前的点是否还有不满足的, 如果不满足一定就是三个点都在圆上了
                    if (sgn(get_distance(p[j], c) - r) > 0) {
                        c.x = (p[i].x + p[j].x) / 2.0;
                        c.y = (p[i].y + p[j].y) / 2.0;
                        r = get_distance(p[j], c);
                        for (int k = 0; k < j; k++) {
                            
                            //找新作出来的圆之前的点是否还有不满足的, 如果不满足一定就是三个点都在圆上了
                            if (sgn(get_distance(p[k], c) - r) > 0) {
                                c = get_circle_center(p[i], p[j], p[k]);
                                r = get_distance(p[i], c);
                            }
                        }
                    }
                }
            }
        }
    }
}solve;

const int maxn = 100 + 10;

Point p[maxn];
double x[maxn], y[maxn], dx[maxn], dy[maxn], v[maxn];

void getp(double t, int n) {
    for (int i = 0; i < n; i ++) {
        p[i].x = x[i] + dx[i] * t * v[i];
        p[i].y = y[i] + dy[i] * t * v[i];
    }
}

bool check(double t, double V, int n) {
    double R = t * V;
    Point c; double r;
    getp(t, n);
    solve.run(p, n, c, r);
    return r <= R;
}

int main() {
//    FILER;
    int n; double V;
    while (scanf("%d%lf",&n,&V) == 2) {
        for (int i = 0; i < n; i ++) {
            scanf("%lf%lf%lf%lf%lf",&x[i],&y[i],&dx[i],&dy[i],&v[i]);
            if (dx[i] == 0 && dy[i] == 0) continue;
//            double temp = sqrt(dx[i]*dx[i] + dy[i]*dy[i]);
//            dx[i] /= temp;
//            dy[i] /= temp;
            if (dx[i] || dy[i]) {
                int fx = dx[i] < 0 ? -1 : 1;
                int fy = dy[i] < 0 ? -1 : 1;
                if (dx[i] == 0) dy[i] = 1;
                else if (dy[i] == 0) dx[i] = 1;
                else {
                    double theta = atan(fabs(dy[i]) / fabs(dx[i]));
                    dx[i] = cos(theta);
                    dy[i] = sin(theta);
                }
                dx[i] *= fx;
                dy[i] *= fy;
            }
        }
        double L = 0, R = 1000000;
        while ((R - L) >= 1e-8) {
            double mid = (L + R) / 2;
            if (check(mid, V, n)) R = mid;
            else L = mid;
        }
        printf("%.4f\n",L);
    }
    
    return 0;
}
