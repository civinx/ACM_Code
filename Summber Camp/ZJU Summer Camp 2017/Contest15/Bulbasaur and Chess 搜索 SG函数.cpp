#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define lson l, mid, rt << 1
#define rson mid+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define MS(x, y) memset(x, y, sizeof(x))

#define left x1, y1, x2, j-1
#define right x1, j+1, x2, y2
#define up x1, y1, i-1, y2
#define down i+1, y1, x2, y2

#define leftup x1, y1, i-1, j-1
#define leftdown i+1, y1, x2, j-1
#define rightup x1, j+1, i-1, y2
#define rightdown i+1, j+1, x2, y2

#define cur x1, y1, x2, y2

using namespace std;
typedef long long LL;

const int maxn = 21;

int f[maxn][maxn][maxn][maxn];

int mp[maxn][maxn];
int n, m;
int mex[10000+10];


int dfs(int x1, int y1, int x2, int y2) {
    int ret = 0;
    
    if (x1 > x2 || y1 > y2) return 0;
    if (f[x1][y1][x2][y2] != -1) return f[x1][y1][x2][y2];
    vector<int> v;
    for (int i = x1; i <= x2; i ++) {
        for (int j = y1; j <= y2; j ++) {
            int op = mp[i][j];
            ret = 0;
            if (op == 1) { // -
                ret ^= dfs(up);
                ret ^= dfs(down);
            } else if (op == 2) { // |
                ret ^= dfs(left);
                ret ^= dfs(right);
            } else { // +
                ret ^= dfs(leftup);
                ret ^= dfs(leftdown);
                ret ^= dfs(rightup);
                ret ^= dfs(rightdown);
            }
//            if(x1==1&&x2==n&&y1==1&&y2==m&&ret==0)
//            {
//                printf("%d %d\n",i,j);
//            }
//            mex[ret] = 1;
            v.push_back(ret);
        }
    }
    MS(mex, 0);
    for (int x : v) mex[x] = 1;
    ret = 0;
    for (int i = 0; i <= 10000; i ++) {
        if (mex[i] == 0) {
            ret = i;
            break;
        }
    }
    return f[x1][y1][x2][y2] = ret;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        MS(f, -1);
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                scanf("%d",&mp[i][j]);
            }
        }
        int res = dfs(1, 1, n, m);
//        printf("%d %d\n",f[1][1][10][5],f[1][7][10][10]);
        if (res) printf("Bulbasaur\n");
        else printf("Totodile\n");
    }
    return 0;
}