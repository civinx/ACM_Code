//
//  main.cpp
//  乘积最大
//
//  Created by czf on 2017/1/21.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 50;
LL dp[maxn][10];
char s[maxn];

LL solve(int L, int R) {
    LL ret = 0;
    for (int i = L; i <= R; i ++) {
        ret = ret * 10 + s[i] - '0';
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, m; scanf("%d%d%s",&n,&m,s);
    for (int i = 0; i < n; i ++) dp[i][0] = solve(0, i);
    for (int k = 1; k <= m; k ++) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                dp[i][k] = max(dp[i][k], dp[j][k-1] * solve(j+1, i));
                //                printf("dp[%d][%d] = %lld\n",i,k,dp[i][k]);
            }
        }
    }
    printf("%lld\n",dp[n-1][m]);
    return 0;
}

//#include <cstdio>
//#include <cstring>
//#include <iostream>
//using namespace std;
//typedef long long LL;
//const int maxn = 50;
//LL dp[maxn][maxn][10];
//char s[maxn];
//
//LL solve(int L, int R) {
//    LL ret = 0;
//    for (int i = L; i <= R; i ++) {
//        ret = ret * 10 + s[i] - '0';
//    }
//    return ret;
//}
//
//int main() {
//    memset(dp, -1, sizeof(dp));
//    int n, m; scanf("%d%d%s",&n,&m,s);
//    for (int i = 0; i < n; i ++) {
//        for (int j = 0; j <= i; j ++) {
//            dp[j][i][0] = solve(j, i);
//        }
//    }
//    for (int k = 1; k <= m; k ++) {
//        for (int i = 0; i < n; i ++) {
//            for (int j = 0; j < i; j ++) {
//                for (int v = j; v < i; v ++) {
//                    dp[j][i][k] = max(dp[j][i][k], dp[j][v][k-1] * solve(v+1, i));
//                    //                    printf("dp[%d][%d][%d] = %lld\n",j,i,k,dp[j][i][k]);
//                }
//            }
//        }
//    }
//    printf("%lld\n",dp[0][n-1][m]);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int max = -1;
//int ma[50];
//
//void DFS(int sum, int K, int head, int N){
//    if (K == 0){
//        if (sum > max) max = sum;
//        return;
//    }
//    int k = 0;
//    for (int i = head; i <= N - K; ++i){
//        k = k * 10 + ma[i];
//        DFS(sum * k, K - 1, i + 1, N);
//    }
//}
//
//int main(int argc, char * argv[]){
//    int N, K;
//    scanf("%d %d", &N, &K);
//    for (int i = 1; i <= N; ++i){
//        scanf("%1d", &ma[i]);
//    }
//    DFS(1, K + 1, 1, N + 1);
//    printf("%d", max);
//    return 0;
//}
