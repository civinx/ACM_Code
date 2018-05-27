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
using namespace std;

typedef long long LL;

const int maxn = 5000 + 100;

char a[maxn], b[maxn];


int cal(char * s, int x, int y) {
    return abs(s[x] - s[y]);
}

int solve(char * s, int len, int m) {
    int ret = 0;
    for (int i = 0; i < len; i ++) { // 左端点
        int sum = 0, l1 = i, r1 = i, l2 = len-1, r2 = len-1; // l2 r2 右串的左右端点
        while (r1 < l2 && l1 <= r1 && l2 <= r2) {
            if (sum + cal(s, r1, l2) <= m) {
                sum += cal(s, r1, l2);
                ret = max(ret, r1 - l1 + 1);
                r1 ++;
                l2 --;
            } else {
                sum-=cal(s, l1, r2);
                sum+=cal(s,r1,l2); 
                l1++;
                r1++;
                l2--;
                r2--;
            }
        }
        
    }
    return ret;
}
int main() {
//    freopen("data.in", "r", stdin);
    int T; scanf("%d",&T);
    while (T--) {
        int m; scanf("%d",&m);
        scanf("%s",a);
        int len = (int)strlen(a);
        for (int i = 0; i < len; i ++) b[i] = a[len-1-i];
        int res = max(solve(a, len, m), solve(b, len, m));
        printf("%d\n",res);
    }
    return 0;
}
