#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;


LL cal(vector<int> v) {
    if (v.size() == 0) {
        return -1;
    }
    LL ret = 0;
    for (int i = (int)v.size()-1; i >= 0; i --) {
        ret = ret * 2 + v[i];
    }
    return ret;
}

vector<int> init(int x) {
    vector<int> ret;
    if (!x) {
        ret.push_back(0);
    }
    while (x) {
        ret.push_back(x & 1);
        x /= 2;
    }
    return ret;
}

vector<int> a, b;
vector<LL> res;

void dfs(int pos, int add, vector<int> v) {
    if (pos >= a.size()) {
        res.push_back(cal(v));
        return;
    }
    for (int i = 0; i <= 1; i ++) {
        if (a[pos] + b[pos] == 0 && add == 1 && pos == a.size()-1) {
            continue;
        }
        int sum = add + (a[pos]^i) + (b[pos]^i);
        if (sum % 2 == i) {
            v.push_back(i);
            if (sum >= 2) {
                if (pos == a.size()-1) {
                    a.push_back(0);
                    b.push_back(0);
                    dfs(pos+1, 1, v);
                    a.pop_back();
                    b.pop_back();
                } else {
                    dfs(pos+1, 1, v);
                }
                v.pop_back();
            } else {
                dfs(pos + 1, 0, v);
                v.pop_back();
            }
        }
    }
}

void solve(int x, int y) {
    a = init(x), b = init(y);
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
    vector<int> v;
    dfs(0, 0, v);
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        int x, y; scanf("%d%d",&x,&y);
        solve(x, y);
        if (res.size() == 0) {
            printf("-1\n");
        } else {
            for (int i = 0; i < res.size(); i ++) {
                printf("%lld%c",res[i],i==res.size()-1?'\n':' ');
            }
        }
        res.clear();
    }
    return 0;
}