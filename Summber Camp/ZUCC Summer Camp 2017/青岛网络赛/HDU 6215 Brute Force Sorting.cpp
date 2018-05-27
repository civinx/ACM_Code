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
#define pb push_back
#define MS(x, y) memset(x, y, sizeof(x))
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;

//const int maxn = 100;
const int maxn = 100000 + 100;
const int INF = 0x3f3f3f3f;

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

struct P {
    int val, pre, nx;
    bool ok;
} a[maxn];

void del(int L, int R) {
    a[a[L].pre].nx = a[R].nx;
    a[a[R].nx].pre = a[L].pre;
}

vector<int> res;
vector<int> v;
vector<int> v2;
bool vis[maxn];

int main() {
    int T; scanf("%d",&T);
    while (T--) {
//        int n; scanf("%d",&n);
        int n; FastIO::rea(n);
        for (int i = 1; i <= n; i ++) {
//            scanf("%d",&a[i].val);
            FastIO::rea(a[i].val);
            a[i].pre = i-1;
            a[i].nx = i+1;
            a[i].ok = 1;
        }
        a[0].nx = 1;
        a[0].val = 0;
        a[n+1].val = INF;
        a[n+1].pre = n;
        v.clear();
        for (int i = 1; i <= n; i ++) v.push_back(i);
        while (1) {
            int L = v[0], R = v[0];
            if (v.back() != n+1) v.push_back(n+1);
            MS(vis, 0);
            for (int i = 0; i < v.size()-1; i ++) {
                if (a[v[i]].val > a[a[v[i]].nx].val) {
                    a[v[i]].ok = a[a[v[i]].nx].ok = 0;
                    if (v[i+1] == a[v[i]].nx) {
                        R = v[i+1];
                    } else {
                        R = v[i+1];
                        del(L, R);
                        if (!vis[a[L].pre] && a[a[L].pre].ok) { v2.push_back(a[L].pre); vis[a[L].pre] = 1; }
                        if (!vis[a[R].nx] && a[a[R].nx].ok) { v2.push_back(a[R].nx); vis[a[R].nx] = 1; }
                        
                        
                        L = R = v[i+1];
                    }
                } else {
                    if (L != R) {
                        del(L, R);
                        if (!vis[a[L].pre] && a[a[L].pre].ok) { v2.push_back(a[L].pre); vis[a[L].pre] = 1; }
                        if (!vis[a[R].nx] && a[a[R].nx].ok) { v2.push_back(a[R].nx); vis[a[R].nx] = 1; }
                    }
                    L = R = v[i+1];
                }
            }
            v.clear();
            for (int i = 0; i < v2.size(); i ++) if (a[v2[i]].ok) v.push_back(v2[i]);
            if (v.size() == 0) break;
            v2.clear();
        }
        
        res.clear();
        for (int i = a[0].nx; i <= n; i = a[i].nx) {
            res.push_back(a[i].val);
        }
        printf("%d\n",(int)res.size());
        for (int i = 0; i < res.size(); i ++) {
            printf("%d ",res[i]);
        }
        printf("\n");
    }
    return 0;
}
