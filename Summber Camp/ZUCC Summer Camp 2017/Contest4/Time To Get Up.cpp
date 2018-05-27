#include <bits/stdc++.h>
using namespace std;

#define lson root << 1, l, mid
#define rson root << 1 | 1, mid + 1, r

typedef long long LL;

const int N = 1e5 + 9;

int n, m;
int a[N];

char M[30][30];
// 0  1  2  3  4  5  6  7  8  9
int gegeg[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int bihua[15] = {0, 0, 1, 7, 4, 0, 0, 8};

int solve(int l, int r) {

    int count = 0;

    for (int j = 1; j <= 7; j ++) {
        for (int i = l; i <= r; i ++) {
            if (M[j][i] == 'X') count ++;
        }
    }

    count /= 2;
    //printf("%d\n", count);

    if (count == 5) {
        if (M[5][l] == 'X' && M[6][l] == 'X') return 2;
        else {
            if (M[2][r] == 'X' && M[3][r] == 'X') return 3;
            else return 5;
        }
    }

    if (count == 6) {
        if (M[4][l + 1] != 'X') return 0;
        else {
            if (M[2][r] == 'X') return 9;
            else return 6;
        }
    }

    return bihua[count];
}

int main() {

    int T;
    for (scanf("%d", &T); T --;) {
        for (int i = 1; i <= 7; i ++) {
            scanf("%s", M[i]);
        }

        //printf("%d\n", solve(0, 3));

        printf("%d%d:%d%d\n", solve(0, 3), solve(5, 8), solve(12, 15), solve(17, 20));
    }

    return 0;
}