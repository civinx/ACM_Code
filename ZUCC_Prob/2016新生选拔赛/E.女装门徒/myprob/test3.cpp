#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct node {
    int hav[3];
    int res[3];
} A[1005];

bool vis[1005];

bool check(int id) {
    for (int i = 0; i < 3; i++)
        if (A[id].hav[i] + A[0].hav[i] < A[id].res[i])
            return false;
    return true;
}

void del(int id) {
    for (int i = 0; i < 3; i++)
        A[0].hav[i] += A[id].hav[i];
}

int main() {
    int T, n, cnt;
    scanf("%d", &T);
    for (int _ = 1; _ <= T; _++) {
        scanf("%d", &n);
        cnt = 0;
        for (int j = 0; j < 3; j++)
            scanf("%d", &A[0].hav[j]);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++)
                scanf("%d", &A[i].hav[j]);
            for (int j = 0; j < 3; j++)
                scanf("%d", &A[i].res[j]);
            vis[i] = false;
        }
        for (int i = 1; i <= n; ) {
            if (!vis[i] && check(i)) {
                vis[i] = true;
                del(i);
                cnt++;
                i = 1;
                continue;
            }
            i++;
        }
        printf("Case #%d: %s\n", _, cnt == n ? "Yes" : "No");
    }
    return 0;
}
