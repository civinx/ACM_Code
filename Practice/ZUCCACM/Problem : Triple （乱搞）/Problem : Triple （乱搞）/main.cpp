//
//  main.cpp
//  Problem : Triple （乱搞）
//
//  Created by czf on 16/3/28.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 1000;
int a[maxn];
int isp[maxn], np[maxn];
bool vis[maxn][maxn];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b,a%b);
}
int main() {
    int t; scanf("%d",&t);
    while(t--) {
        memset(vis, 0, sizeof(vis));
        memset(isp, 0, sizeof(isp));
        memset(np, 0, sizeof(np));
        int n; scanf("%d",&n);
        int sum = n*(n-1)*(n-2)/6;
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++){
                if (j == i || vis[i][j]) continue;
                vis[i][j] = vis[j][i] = 1;
                if (gcd(a[i],a[j]) == 1){
                    isp[i] ++;
                    isp[j] ++;
                }
                else {
                    np[i] ++;
                    np[j] ++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i ++) ans += isp[i] * np[i];
        ans /= 2;
        int res = sum - ans;
        printf("%d\n",res);
    }
    return 0;
}
