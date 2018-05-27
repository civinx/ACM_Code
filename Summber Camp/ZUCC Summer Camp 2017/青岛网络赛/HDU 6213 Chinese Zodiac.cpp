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

const int maxn = 8;

string S[12] = {"rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "rooster", "dog", "pig"};

int solve(string & s) {
    for (int i = 0; i < 12; i ++) {
        if (s == S[i]) return i;
    }
    return -1;
}

int main() {
    int T; scanf("%d",&T);
    while (T--) {
        string s1, s2; cin >> s1 >> s2;
        int t1 = solve(s1); int t2 = solve(s2);
        int res = 0;
        if (t2 > t1) {
            res = t2 - t1;
        } else {
            res = 12 - (t1 - t2);
        }
        if (res == 0) {
            printf("12\n");
        } else {
            printf("%d\n",res);
        }
    }
    return 0;
}