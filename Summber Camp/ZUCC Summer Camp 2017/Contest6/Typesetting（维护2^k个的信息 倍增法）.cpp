#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MS(x, y) memset(x, y, sizeof(x))
using namespace std;

const int MAXN = 100000 + 100;

//const int MAXN = 20;

int a[MAXN], f1[MAXN][30], f2[MAXN][30], tmp1[MAXN], tmp2[MAXN];

int n, w, pw, dw;;

void getPre(int w, int f[]) {
    int sum = -1, pos = 1;
    for (int i = 1; i <= n; i ++) {
        while (pos <= n && sum + a[pos] + 1 <= w) {
            sum += a[pos] + 1;
            pos ++;
        }
        f[i] = pos - i;
        sum -= a[i] + 1;
    }
}

void getST(int f[][30]) {
    for (int k = 1; k < 30; k ++) {
        for (int i = 1; i <= n; i ++) {
            f[i][k] = f[i][k-1] + f[i+f[i][k-1]][k-1];
        }
    }
}

void work() {
    getPre(w, tmp1);
    for (int i = 1; i <= n; i ++) f1[i][0] = tmp1[i];
    getST(f1);
    getPre(dw, tmp1); getPre(w-dw-pw, tmp2);
    for (int i = 1; i <= n; i ++) f2[i][0] = tmp1[i] + tmp2[tmp1[i]+i];
    getST(f2);
}

int solve1(int f[][30], int cur) {
    int ret = 0, k = 0;
    while (cur <= n) {
        k = 0;
        while (cur + f[cur][k+1] <= n) k ++;
        ret += (1 << k);
        cur += f[cur][k];
//        printf("solve1\n");
    }
    return ret;
}

void solve2(int f[][30], int & cur, int x) {
    if (x == 0) {
        return;
    }
    int k = 0;
    while (cur <= n && x) {
        k = 0;
        while ((1 << (k+1)) <= x) k ++;
        x -= (1 << k);
        cur += f[cur][k];
//        printf("solve2\n");
    }
    
}

int main() {
//        freopen("1012.in", "r", stdin);
//        freopen("test.out", "w", stdout);
    int T; scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d%d",&n,&w,&pw,&dw);
        for (int i = 1; i <= n; i ++) scanf("%d",&a[i]);
        work();
        int q; scanf("%d",&q);
        while (q--) {
            int res = 0, cur = 1;
            int x, h; scanf("%d%d",&x,&h);
            int tmp = solve1(f1, 1);
            if (tmp <= x - 1) {
                printf("%d\n",tmp+h);
                continue;
            }
            res = x + h - 1;
            solve2(f1, cur, x-1);
            solve2(f2, cur, h);
            if (cur <= n) {
                res += solve1(f1, cur);
            }
            printf("%d\n",res);
        }
    }
    return 0;
}