// 模版.cpp

// 最大流
struct Edge {
    int from, to;
    LL cap, flow;;
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    bool vis[MAXN];
    int d[MAXN];
    int cur[MAXN];
    
    void AddEdge(int from, int to, LL cap) {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    
    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); i ++) {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    
    LL DFS(int x, LL a) {
        if (x == t || a == 0) return a;
        LL flow = 0, f;
        for (int & i = cur[x]; i < G[x].size(); i ++) {
            Edge & e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    
    LL Maxflow(int s, int t) {
        this->s = s; this->t = t;
        LL flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
};

// 费用流
const int maxn = 510;
const int INF = 0x3f3f3f3f;
const int MAXN = ?;
struct MCMF {
    struct Edge {
        int from, to, cap, flow, cost;
    };
    int n, m, s, t;
    // 注意MAXN的大小不一定是原图点的大小
    int inq[MAXN];
    int d[MAXN];
    int p[MAXN];
    int a[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];
    
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i ++) G[i].clear();
        edges.clear();
    }
    
    void AddEdge(int from, int to, int cap, int cost) {
        edges.push_back((Edge){from, to, cap, 0, cost});
        edges.push_back((Edge){to, from, 0, 0, -cost});
        int m = (int)edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    
    bool BellmanFord(int s, int t, int &flow, int &cost) {
        for (int i = 0; i <= n; i ++) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;
        
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i ++) {
                Edge & e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {Q.push(e.to); inq[e.to] = 1;}
                }
            }
        }

        // 此处有技巧，如果要求最大收益，那么收益的边是负数，当d[t] > 0就说明没有收益，返回false
        // if (d[t] > 0) return false;
        if (d[t] == INF) return false;
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while (u != s) {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }
    
    void Mincost(int s, int t, int &flow, int &cost) {
        flow = 0, cost = 0;
        while (BellmanFord(s, t, flow, cost));
    }
} solve;


// 线性素数筛
int prime[MAXN];//保存素数
bool vis[MAXN];//初始化
int Prime(int n) {
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i < n; i ++) {
        if(!vis[i])
            prime[cnt++] = i;
        for(int j = 0; j < cnt && i * prime[j] < n; j ++) {
            vis[i * prime[j]]=1;
            if(i % prime[j] == 0)//关键
                break;
        }
    }
    return cnt;//返回小于n的素数的个数 
}

// 2D几何模版
struct Geometry_2D {
    
    const int INF = 0x3f3f3f3f;
    const double eps = 1e-6;

    struct Point {
        double x, y;
        Point() {}
        Point(double _x, double _y) : x(_x), y(_y) {}
        bool operator == (const Point & rhs) const {
            return x == rhs.x && y == rhs.y;
        }
    };

    typedef Point Vect;
    
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

    //得到三角形外接圆的圆心
    Point get_circle_center(const Point &a, const Point &b, const Point &c) {
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

    // 求最小圆覆盖
    void min_cover_circle(Point *p, int n, Point &c, double &r) {
//        random_shuffle(p, p + n);//随机函数,使用了之后使程序更快点,也可以不用
        c = p[0];
        r = 0;
        for (int i = 1; i < n; i++) {
            if (sgn(getDist(p[i], c) - r) > 0){ //找新作出来的圆之前的点是否还有不满足的, 如果不满足一定就是三个点都在圆上了
                c = p[i];//圆心为当前点
                r = 0;//这时候这个圆只包括他自己.所以半径为0
                for (int j = 0; j < i; j++) { //找新作出来的圆之前的点是否还有不满足的, 如果不满足一定就是三个点都在圆上了
                    if (sgn(getDist(p[j], c) - r) > 0) { //找新作出来的圆之前的点是否还有不满足的, 如果不满足一定就是三个点都在圆上了
                        c.x = (p[i].x + p[j].x) / 2.0;
                        c.y = (p[i].y + p[j].y) / 2.0;
                        r = getDist(p[j], c);
                        for (int k = 0; k < j; k++) {
                            if (sgn(getDist(p[k], c) - r) > 0) { //找新作出来的圆之前的点是否还有不满足的, 如果不满足一定就是三个点都在圆上了
                                c = get_circle_center(p[i], p[j], p[k]);
                                r = getDist(p[i], c);
                            }
                        }
                    }
                }
            }
        }
    }
};

// Floyd
struct Floyd {
    int d[maxn][maxn];
    int n;
    
    void init(int n) {
        MS(d, INF);
        this->n = n;
        for (int i = 1; i <= n; i ++) d[i][i] = 0;
    }
    
    void run() {
        for (int k = 1; k <= n; k ++) {
            for (int i = 1; i <= n; i ++) {
                for (int j = 1; j <= n; j ++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
};

// Dijkstra
struct Dijkstra {
    struct Edge {
        int from, to;
        LL cost;
    };
    
    vector<int> G[maxn];
    vector<Edge> edges;
    
    void AddEdge(int u, int v, LL cost) {
        edges.push_back((Edge){u, v, cost});
        int m = (int)edges.size()-1;
        G[u].push_back(m);
    }
    
    LL d[maxn];
    int n, m;
    
    struct P {
        int id; LL dist;
        bool operator > (const P & rhs) const {
            return dist > rhs.dist;
        }
    };
    
    void run(int s) {
        for (int i = 1; i <= n; i ++) d[i] = INF;
        d[s] = 0;
        priority_queue<P, vector<P>, greater<P> > q;
        q.push((P){s, 0});
        while (!q.empty()) {
            P cur = q.top(); q.pop();
            if (cur.dist != d[cur.id]) continue;
            for (int i = 0; i < G[cur.id].size(); i ++) {
                Edge & e = edges[G[cur.id][i]];
                int from = e.from, to = e.to; LL cost = e.cost;
                if (d[to] > d[from] + e.cost) {
                    d[to] = d[from] + cost;
                    q.push((P){to, d[to]});
                }
            }
        }
    }
    
    void init() {
        for (int i = 1; i <= n; i ++) G[i].clear();
        edges.clear();
    }
};

// 次短路
namespace SecShort {
    LL d1[maxn], d2[maxn];
    struct Edge {
        int from, to; LL cost;
    };
    vector<int> G[maxn];
    vector<Edge> edges;
    
    void init(int n) {
        for (int i = 1; i <= n; i ++) G[i].clear();
        edges.clear();
        MS(d1, 0x3f);
        MS(d2, 0x3f);
    }
    
    void AddEdge(int from, int to, LL cost) {
        edges.push_back(Edge{from, to, cost});
        int m = (int)edges.size()-1;
        G[from].push_back(m);
    }
    
    struct P {
        int id; LL dist;
        bool operator > (const P & rhs) const {
            return dist > rhs.dist;
        }
    };
    
    void solve(int s) {
        d1[s] = 0;
        priority_queue<P, vector<P>, greater<P> > q;
        q.push((P){s, 0});
        while (!q.empty()) {
            P cur = q.top(); q.pop();
            if (cur.dist > d2[cur.id]) continue;
            for (int i = 0; i < G[cur.id].size(); i ++) {
                Edge & e = edges[G[cur.id][i]];
                LL dist = cur.dist + e.cost;
                if (dist < d1[e.to]) {
                    swap(dist, d1[e.to]);
                    q.push(P{e.to, d1[e.to]});
                }
                if (dist < d2[e.to]) {
                    d2[e.to] = dist;
                    q.push(P{e.to, d2[e.to]});
                }
            }
        }
    }
};

// 用A-Star求第K短路
namespace KShort {
    LL h[maxn];
    
    struct Edge {
        int from, to; LL cost;
    };
    vector<int> G[2][maxn]; // 0代表正向图 1代表反向图
    vector<Edge> edges[2];
    
    int n;
    void init(int n) {
        KShort::n = n;
        for (int i = 1; i <= n; i ++) G[0][i].clear(), G[1][i].clear();
        edges[0].clear(); edges[1].clear();
    }
    
    void AddEdge(int from, int to, LL cost, int op) {
        edges[op].push_back(Edge{from, to, cost});
        int m = (int)edges[op].size()-1;
        G[op][from].push_back(m);
    }
    
    // 在反向图上跑最短路
    void dijkstra(int s) {
        struct P {
            int id; LL val;
            bool operator > (const P & rhs) const {
                return val > rhs.val;
            }
        };
        for (int i = 1; i <= n; i ++) h[i] = INF;
        h[s] = 0;
        priority_queue<P, vector<P>, greater<P> > q;
        q.push((P){s, 0});
        while (!q.empty()) {
            P cur = q.top(); q.pop();
            if (cur.val != h[cur.id]) continue;
            for (int i = 0; i < G[1][cur.id].size(); i ++) {
                Edge & e = edges[1][G[1][cur.id][i]];
                int from = e.from, to = e.to; LL cost = e.cost;
                if (h[to] > h[from] + e.cost) {
                    h[to] = h[from] + cost;
                    q.push((P){to, h[to]});
                }
            }
        }
    }
    
    LL solve(int s, int t, int k) {
        struct P {
            int id; LL g, h;
            bool operator > (const P & rhs) const {
                return g + h > rhs.g + rhs.h;
            }
        };
        dijkstra(t);
        priority_queue<P, vector<P>, greater<P> > q;
        q.push(P{s, 0, h[s]});
        int cnt = 0;
        while (!q.empty()) {
            P cur = q.top(); q.pop();
            if (cur.id == t) {
                cnt ++;
                if (cnt == k) return cur.g;
            }
            for (int i = 0; i < G[0][cur.id].size(); i ++) {
                Edge & e = edges[0][G[0][cur.id][i]];
                q.push(P{e.to, cur.g+e.cost, h[e.to]});
            }
        }
        return -1;
    }
};



// 树链剖分
struct TreeCut {
    struct Seg {
        int l, r, mx, sum;
    };
    vector<int> G[maxn];
    Seg t[maxn<<4];
    int dep[maxn], size[maxn], fa[maxn], pos[maxn], bl[maxn], son[maxn];
    int sz;
    
    void init(int n) {
        for (int i = 1; i <= n; i ++) G[i].clear();
        sz = 0;
        MS(size, 0);
    }
    
    void AddEdge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    void dfs1(int x) {
        size[x] = 1;
        int mx_son = 0;
        for (int i = 0; i < G[x].size(); i ++) {
            int to = G[x][i];
            if (to == fa[x]) continue;
            dep[to] = dep[x] + 1;
            fa[to] = x;
            dfs1(to);
            size[x] += size[to];
            if (size[to] > size[mx_son]) {
                mx_son = to;
            }
        }
        son[x] = mx_son;
    }
    
    void dfs2(int x, int chain) {
        sz ++;
        pos[x] = sz;
        bl[x] = chain;
        if (!son[x]) return;
        dfs2(son[x], chain);
        for (int i = 0; i < G[x].size(); i ++) {
            int to = G[x][i];
            if (to == fa[x] || to == son[x]) continue;
            dfs2(to, to);
        }
    }
    
    void build(int l, int r, int rt) {
        t[rt].l = l; t[rt].r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
    }
    
    void pushup(int rt) {
        t[rt].sum = t[ls].sum + t[rs].sum;
        t[rt].mx = max(t[ls].mx, t[rs].mx);
    }
    
    void change(int x, int v, int rt) {
//        int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1;
        INIT;
        if (l == r) {
            t[rt].sum = v;
            t[rt].mx = v;
            return;
        }
        if (x <= mid) {
            change(x, v, ls);
        } else {
            change(x, v, rs);
        }
        pushup(rt);
    }
    
    int querysum(int L, int R, int rt) {
//        int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1;
        INIT;
        if (L <= l && r <= R) {
            return t[rt].sum;
        }
        int ret = 0;
        if (L <= mid) ret += querysum(L, R, ls);
        if (R > mid) ret += querysum(L, R, rs);
        return ret;
    }
    
    int querymx(int L, int R, int rt) {
//        int l = t[rt].l, r = t[rt].r, mid = (l + r) >> 1
        INIT;
        if (L <= l && r <= R) {
            return t[rt].mx;
        }
        int ret = -INF;
        if (L <= mid) ret = querymx(L, R, ls);
        if (R > mid) ret = max(ret, querymx(L, R, rs));
        return ret;
    }
    
    int solvesum(int x, int y) {
        int ret = 0;
        while (bl[x] != bl[y]) {
            if (dep[bl[x]] < dep[bl[y]]) swap(x, y);
            ret += querysum(pos[bl[x]], pos[x], 1);
            x = fa[bl[x]];
        }
        if (pos[x] > pos[y]) swap(x, y);
        ret += querysum(pos[x], pos[y], 1);
        return ret;
    }
    
    int solvemx(int x, int y) {
        int ret = -INF;
        while (bl[x] != bl[y]) {
            if (dep[bl[x]] < dep[bl[y]]) swap(x, y);
            ret = max(ret, querymx(pos[bl[x]], pos[x], 1));
            x = fa[bl[x]];
        }
        if (pos[x] > pos[y]) swap(x, y);
        ret = max(ret, querymx(pos[x], pos[y], 1));
        return ret;
    }
};

// 求所有线性数列
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

ll _,n;
namespace linear_seq {
    const ll N=10010;
    ll res[N],base[N],_c[N],_md[N];

    vector<int> Md;
    void mul(ll *a,ll *b,ll k) {
        rep(i,0,k+k) _c[i]=0;
        rep(i,0,k) if (a[i]) rep(j,0,k) _c[i+j]=(_c[i+j]+a[i]*b[j])%mod;
        for (ll i=k+k-1;i>=k;i--) if (_c[i])
            rep(j,0,SZ(Md)) _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%mod;
        rep(i,0,k) a[i]=_c[i];
    }
    ll solve(ll n,VI a,VI b) {
//        printf("%d\n",SZ(b));
        ll ans=0,pnt=0;
        ll k=SZ(a);
        assert(SZ(a)==SZ(b));
        rep(i,0,k) _md[k-1-i]=-a[i];_md[k]=1;
        Md.clear();
        rep(i,0,k) if (_md[i]!=0) Md.push_back(i);
        rep(i,0,k) res[i]=base[i]=0;
        res[0]=1;
        while ((1ll<<pnt)<=n) pnt++;
        for (ll p=pnt;p>=0;p--) {
            mul(res,res,k);
            if ((n>>p)&1) {
                for (ll i=k-1;i>=0;i--) res[i+1]=res[i];res[0]=0;
                rep(j,0,SZ(Md)) res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%mod;
            }
        }
        rep(i,0,k) ans=(ans+res[i]*b[i])%mod;
        if (ans<0) ans+=mod;
        return ans;
    }
    VI BM(VI s) {
        VI C(1,1),B(1,1);
        ll L=0,m=1,b=1;
        rep(n,0,SZ(s)) {
            ll d=0;
            rep(i,0,L+1) d=(d+(ll)C[i]*s[n-i])%mod;
            if (d==0) ++m;
            else if (2*L<=n) {
                VI T=C;
                ll c=mod-d*powmod(b,mod-2)%mod;
                while (SZ(C)<SZ(B)+m) C.pb(0);
                rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
                L=n+1-L; B=T; b=d; m=1;
            } else {
                ll c=mod-d*powmod(b,mod-2)%mod;
                while (SZ(C)<SZ(B)+m) C.pb(0);
                rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
                ++m;
            }
        }
        return C;
    }
    ll gao(VI a,ll n) {
        VI c=BM(a);
        c.erase(c.begin());
        rep(i,0,SZ(c)) c[i]=(mod-c[i])%mod;
        return solve(n,c,VI(a.begin(),a.begin()+SZ(c)));
    }
};


int main() {
    for (scanf("%lld",&_);_;_--) {
        scanf("%lld",&n);
        printf("%lld\n",linear_seq::gao(VI{1,3,6,12,20,35,54,86,128},n-1));
    }
}

// AVL树
template <typename T>
struct Node {
    Node *lson, *rson;
    int height;
    T data;
    
    Node() : lson(NULL), rson(NULL), height(0), data(0) {}
    
    Node(Node * lson, Node * rson, int height, T data) {
        this->lson = lson;
        this->rson = rson;
        this->height = height;
        this->data = data;
    }
};

template <typename T>
struct Node {
    Node *lson, *rson;
    int height;
    T data;
    
    Node() : lson(NULL), rson(NULL), height(0), data(0) {}
    
    Node(Node * lson, Node * rson, int height, T data) {
        this->lson = lson;
        this->rson = rson;
        this->height = height;
        this->data = data;
    }
};

template<typename T>
class AVLTree {
    
public:
    AVLTree() : root(NULL) {};
    
    T get_root() {
        if (root == NULL) return -1;
        return root->data;
    }
    
    void insert(T data) {
        root = insert(root, data);
    }
    
    void erase(T data) {
        Node<T> * target = find_node(root, data);
        erase(root, target);
    }
    
    vector<T> preorder() {
        vector<T> ret;
        preorder(root, ret);
        return ret;
    }
    
    vector<T> inorder() {
        vector<T> ret;
        inorder(root, ret);
        return ret;
    }
    
    vector<T> postorder() {
        vector<T> ret;
        postorder(root, ret);
        return ret;
    }
    
    vector<T> levelorder() {
        vector<T> ret;
        levelorder(root, ret);
        return ret;
    }
    
    bool is_complete() {
        return is_complete(root);
    }
    
private:
    Node<T> * root;
    
    Node<T> * create_node(Node<T> * lson, Node<T> * rson, int height, T data) {
        return new Node<T>(lson, rson, height, data);
    }
    
    int get_height(Node<T> * tree) {
        return tree ? tree->height : 0;
    }
    
    void set_height(Node<T> * tree) {
        if (tree == NULL) return;
        tree->height = max(get_height(tree->lson), get_height(tree->rson)) + 1;
    }
    
    Node<T> * left_left_rotation(Node<T> * t1) {
        Node<T> * t2 = t1->lson;
        t1->lson = t2->rson;
        t2->rson = t1;
        
        set_height(t1);
        set_height(t2);
        
        return t2;
    }
    
    Node<T> * right_right_rotation(Node<T> * t1) {
        Node<T> * t2 = t1->rson;
        t1->rson = t2->lson;
        t2->lson = t1;
        
        set_height(t1);
        set_height(t2);
        
        return t2;
    }
    
    Node<T> * left_right_rotation(Node<T> * t1) {
        t1->lson = right_right_rotation(t1->lson);
        return left_left_rotation(t1);
    }
    
    Node<T> * right_left_rotation(Node<T> * t1) {
        t1->rson = left_left_rotation(t1->rson);
        return right_right_rotation(t1);
    }
    
    Node<T> * insert(Node<T> * tree, T data) {
        if (tree == NULL) {
            tree = create_node(NULL, NULL, 0, data);
        } else if (data < tree->data) {
            tree->lson = insert(tree->lson, data);
            if (get_height(tree->lson) - get_height(tree->rson) == 2) {
                if (data < tree->lson->data) {
                    tree = left_left_rotation(tree);
                } else {
                    tree = left_right_rotation(tree);
                }
            }
        } else if (data > tree->data) {
            tree->rson = insert(tree->rson, data);
            if (get_height(tree->rson) - get_height(tree->lson) == 2) {
                if (data > tree->rson->data) {
                    tree = right_right_rotation(tree);
                } else {
                    tree = right_left_rotation(tree);
                }
            }
        } else {
            // 默认不添加相同节点
        }
        set_height(tree);
        return tree;
    }
    
    Node<T> * find_max_node(Node<T> * tree) {
        if (tree == NULL) {
            return NULL;
        }
        while (tree->rson != NULL) {
            tree = tree->rson;
        }
        return tree;
    }
    
    Node<T> * find_min_node(Node<T> * tree) {
        if (tree == NULL) {
            return NULL;
        }
        while (tree->lson != NULL) {
            tree = tree->lson;
        }
        return tree;
    }
    
    Node<T> * find_node(Node<T> * tree, T data) {
        while (tree) {
            if (data < tree->data) {
                tree = tree->lson;
            } else if (data > tree->data) {
                tree = tree->rson;
            } else {
                break;
            }
        }
        return tree;
    }
    
    Node<T> * erase(Node<T> * tree, Node<T> * target) {
        if (tree == NULL || target == NULL) {
            return NULL;
        }
        if (target->data < tree->data) {
            tree->lson = erase(tree->lson, target);
            if (get_height(tree->rson) - get_height(tree->lson) == 2) {
                Node<T> * r = tree->rson;
                if (get_height(r->lson) > get_height(r->rson)) {
                    tree = right_left_rotation(tree);
                } else {
                    tree = rihgt_right_rotation(tree);
                }
            }
        } else if (target->data > tree->data) {
            tree->rson = erase(tree->rson, target);
            if (get_height(tree->lson) - get_height(tree->rson) == 2) {
                Node<T> * l = tree->lson;
                if (get_height(l->lson) > get_height(l->rson)) {
                    tree = left_left_rotation(tree);
                } else {
                    tree = left_right_rotation(tree);
                }
            }
        } else {
            if (tree->lson && tree->rson) {
                if (get_height(tree->lson) > get_height(tree->rson)) {
                    Node<T> * mx = find_max_node(tree->lson);
                    tree->data = mx->data;
                    tree->lson = erase(tree->lson, mx);
                } else {
                    Node<T> * mi = find_min_node(tree->rson);
                    tree->data = mi->data;
                    tree->rson = erase(tree->rson, mi);
                }
            } else {
                Node<T> * temp = tree;
                tree = tree->lson ? tree->lson : tree->rson;
                delete temp;
            }
        }
        return tree;
    }
    
    void preorder(Node<T> * tree, vector<T> & v) {
        if (tree == NULL) return;
        v.push_back(tree->data);
        preorder(tree->lson, v);
        preorder(tree->rson, v);
    }
    
    void inorder(Node<T> * tree, vector<T> & v) {
        if (tree == NULL) return;
        inorder(tree->lson, v);
        v.push_back(tree->data);
        inorder(tree->rson, v);
    }
    
    void postorder(Node<T> * tree, vector<T> & v) {
        if (tree == NULL) return;
        postorder(tree->lson, v);
        postorder(tree->rson, v);
        v.push_back(tree->data);
    }
    
    void levelorder(Node<T> * tree, vector<T> & v) {
        if (tree == NULL) return;
        queue<Node<T> * > q; q.push(tree);
        while (!q.empty()) {
            Node<T> * cur = q.front(); q.pop();
            v.push_back(cur->data);
            if (cur->lson) q.push(cur->lson);
            if (cur->rson) q.push(cur->rson);
        }
    }
    
    bool is_complete(Node<T> * tree) {
        if (tree == NULL) return false;
        queue<Node<T> * > q; q.push(tree);
        while (!q.empty()) {
            Node<T> * cur = q.front(); q.pop();
            if (cur == NULL) break;
            q.push(cur->lson);
            q.push(cur->rson);
        }
        while (!q.empty()) {
            Node<T> * cur = q.front(); q.pop();
            if (cur != NULL) return false;
        }
        return true;
    }
};

// AC自动机
struct AC_auto {
    static const int MAXN = 500000 + 100;
//    static const int MAXN = 100;
    static const int SIZE = 26;
    int ch[MAXN][SIZE], fail[MAXN], val[MAXN];
    int root, sz;
    
    int newnode() {
        MS(ch[sz], -1);
        val[sz] = 0;
        return sz++;
    }
    
    void init() {
        sz = 0;
        newnode();
    }
    
    int getid(char c) {
        return c - 'a';
    }
    
    void insert(char * s) {
        int len = (int)strlen(s);
        int cur = root;
        for (int i = 0; i < len; i ++) {
            int id = getid(s[i]);
            if (ch[cur][id] == -1) {
                ch[cur][id] = newnode();
            }
            cur = ch[cur][id];
        }
        val[cur] ++;
    }
    
    void build() {
        queue<int> q;
        fail[root] = root;
        for (int i = 0; i < SIZE; i ++) {
            int & son = ch[root][i];
            if (son == -1) {
                son = root;
            } else {
                fail[son] = root;
                q.push(son);
            }
        }
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int i = 0; i < SIZE; i ++) {
                int & son = ch[cur][i];
                if (son == -1) {
                    son = ch[fail[cur]][i];
                } else {
                    fail[son] = ch[fail[cur]][i];
                    q.push(son);
                }
            }
        }
    }
    
    // 有几个单词在文章出现过
    int query(char * s) {
        int len = (int)strlen(s);
        int cur = root;
        int ret = 0;
        for (int i = 0; i < len; i ++) {
            int id = getid(s[i]);
            cur = ch[cur][id];
            int temp = cur;
            while (temp != root) {
                ret += val[temp];
                val[temp] = 0;
                temp = fail[temp];
            }
        }
        return ret;
    }
}AC;

// 输入挂
namespace FastIO {
    char buf[100000],*p1=buf,*p2=buf;
    inline char nc(){
        return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
    }
    inline bool rea(int & x){
        char c=nc();x=0;
        if(c==EOF) return false;
        for(;!isdigit(c);c=nc());
        for(;isdigit(c);x=x*10+c-'0',c=nc());
        return true;
    }
    inline bool rea(LL & x){
        char c=nc();x=0;
        if(c==EOF) return false;
        for(;!isdigit(c);c=nc());
        for(;isdigit(c);x=x*10+c-'0',c=nc());
        return true;
    }
}

// 主席树（查询二维矩形点的个数 每列只有一个点）
struct MultiSegTree {
    struct Node {
        int lson, rson, sum;
        Node () {lson = rson = sum = 0;};
    }T[maxn * 40];
    
    int n, cnt, root[maxn];
    
    void init(int n) {
        MS(root, 0);
        cnt = 0;
        this->n = n;
    }
    
    void insert(int l, int r, int & cur, int pre, int pos) {
        T[++cnt] = T[pre]; T[cnt].sum ++; cur = cnt;
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (pos <= mid) insert(l, mid, T[cur].lson, T[pre].lson, pos);
        else insert(mid+1, r, T[cur].rson, T[pre].rson, pos);
    }
    
    int query(int l, int r, int L, int R, int cur, int pre) {
        if (L <= l && r <= R) return T[cur].sum - T[pre].sum;
        int mid = (l + r) >> 1;
        int ret = 0;
        if (L <= mid) ret += query(l, mid, L, R, T[cur].lson, T[pre].lson);
        if (R > mid) ret += query(mid+1, r, L, R, T[cur].rson, T[pre].rson);
        return ret;
    }
    
    LL ask(int l, int d, int r, int u) {
        if (l > r || d > u) return 0;
        return (LL)query(1, n, d, u, root[r], root[l-1]);
    }
}T;

struct point {
    int x,y;
};
point list[MAXN];
int stack[MAXN],top;

int cross(point p0,point p1,point p2) //计算叉积  p0p1 X p0p2 
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}    
double dis(point p1,point p2)  //计算 p1p2的 距离 
{
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}    
bool cmp(point p1,point p2) //极角排序函数 ， 角度相同则距离小的在前面 
{
    int tmp=cross(list[0],p1,p2);
    if(tmp>0) return true;
    else if(tmp==0&&dis(list[0],p1)<dis(list[0],p2)) return true;
    else return false;
}    
void init(int n) //输入，并把  最左下方的点放在 list[0]  。并且进行极角排序 
{
    int i,k;
    point p0;
    scanf("%d%d",&list[0].x,&list[0].y);
    p0.x=list[0].x;
    p0.y=list[0].y;
    k=0;
    for(i=1;i<n;i++) {
        scanf("%d%d",&list[i].x,&list[i].y);
        if( (p0.y>list[i].y) || ((p0.y==list[i].y)&&(p0.x>list[i].x)) ) {
            p0.x=list[i].x;
            p0.y=list[i].y;
            k=i;
        }    
    }    
    list[k]=list[0];
    list[0]=p0;
    
    sort(list+1,list+n,cmp);
}     

void graham(int n) {
    int i;
    if(n==1) {top=0;stack[0]=0;}
    if(n==2) {
        top=1;
        stack[0]=0;
        stack[1]=1;
    }    
    if(n>2) {
        for(i=0;i<=1;i++) stack[i]=i;
        top=1;
        for(i=2;i<n;i++) {
            while(top>0&&cross(list[stack[top-1]],list[stack[top]],list[i])<=0) top--;
            top++;
            stack[top]=i;
        }    
    }    
}    

// 威佐夫游戏
rate = (618033988, 749894848, 204586834)
MOD = 1000000000

T = int(input())
for _ in range(T):
    n, m = list(map(int, input().split()))
    if n > m:
        n, m = m, n
    dist = m - n
    pre = dist // MOD
    last = dist % MOD
    x = last * rate[2]
    y = last * rate[1] + pre * rate[2] + x // MOD
    z = last * rate[0] + pre * rate[1] + y // MOD
    r = pre * rate[0] + z // MOD + dist
    print('A' if r != n else 'B')

