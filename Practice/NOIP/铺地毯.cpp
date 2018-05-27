//
// Created by CZF on 2017/2/13.
//
#include <vector>
#include <cstdio>
using namespace std;

vector<pair<pair<int, int>, pair<int, int> > > v;

int main() {
    int n; scanf("%d",&n);
    for (int i = 0; i < n; i ++) {
        int x, y, lx, ly; scanf("%d%d%d%d",&x,&y,&lx,&ly);
        v.push_back(make_pair(make_pair(x, y), make_pair(x+lx, y+ly)));
    }
    int x, y, res = -1; scanf("%d%d",&x,&y);
    for (int i = v.size()-1; i >= 0; i --) {
        int x1 = v[i].first.first, y1 = v[i].first.second;
        int x2 = v[i].second.first, y2 = v[i].second.second;
        if (x1 <= x && y1 <= y && x2 >= x && y2 >= y) {
            res = i + 1;
            break;
        }
    }
    printf("%d\n",res);
    return 0;
}
