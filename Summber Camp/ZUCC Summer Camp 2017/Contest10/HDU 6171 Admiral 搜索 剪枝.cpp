#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
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
#define FILER freopen("data.in", "r", stdin)
#define FILEW freopen("data.out", "w", stdout)
using namespace std;
typedef long long LL;
const int maxn = 6;
const int dir[4][2] = {{-1,-1}, {-1,0}, {1,0}, {1,1}};
const LL END = 751637788911935ll;
int a[maxn][maxn], pos[maxn][maxn];
LL pw[21];

LL getState(int & x, int & y) {
    LL ret = 0;
    int cnt = 20;
    for (int i = 0; i < maxn; i ++) {
        for (int j = 0; j <= i; j ++) {
            scanf("%d",&a[i][j]);
            if (a[i][j] == 0) {
                x = i;
                y = j;
            }
            ret = ret * 6 + a[i][j];
            pos[i][j] = cnt--;
        }
    }
    return ret;
}

LL changeState(int x, int y, int xx ,int yy, LL state) {
    LL pos1 = pos[x][y], pos2 = pos[xx][yy];
    LL nx = a[xx][yy];
    state -= nx * pw[pos2];
    state += nx * pw[pos1];
    return state;
}
//
bool check() {
    for (int i = 0; i < maxn; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (a[i][j] != i) return false;
        }
    }
    return true;
}

int res = 100;
void dfs(int x, int y, int step, int fx, int fy) {
    if (step > 20 || step >= res) {
        return;
    }
    if (x == 0 && y == 0 && check()) {
        res = min(res, step);
        return;
    }
    if (x > 20 - step) return;
    
    for (int i = 0; i < 4; i ++) {
        if (x == 20 - step) {
            if (i == 2 || i == 3) continue;
        }
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx == fx && yy == fy) continue;
        if (xx < 0 || yy < 0) continue;
        if (xx >= maxn || y >= maxn) continue;
        if (yy > xx) continue;
        swap(a[x][y], a[xx][yy]);
        dfs(xx, yy, step+1, x, y);
        swap(a[x][y], a[xx][yy]);
    }
}

void init() {
    pw[0] = 1;
    for (int i = 1; i <= 20; i ++) pw[i] = pw[i-1] * 6;
}

int main() {
    init();
    int T; scanf("%d",&T);
    while (T--) {
        res = 100;
        int x, y;
        LL state;
        state = getState(x, y);
        dfs(x, y, 0, x, y);
        if (res > 20) printf("too difficult\n");
        else printf("%d\n",res);
    }
    return 0;
}