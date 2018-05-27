//
//  main.cpp
//  5495 LCS
//
//  Created by czf on 16/3/17.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 1000000 + 100;
int a[maxn], b[maxn], p[maxn];
bool vis[maxn];

int main(){
    int t; scanf("%d",&t);
    while(t--){
        memset(vis, 0, sizeof(vis));
        int n; scanf("%d",&n);
        int cnt = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
            p[a[i]] = i;
        }
        for(int i = 0; i < n; i ++) scanf("%d",&b[i]);
        for(int i = 0; i < n; i ++){
            if (vis[i]) continue;
            vis[i] = 1;
            int ans = 1;
            int j = i;
            while(b[j] != a[i]){
                j = p[b[j]];
                vis[j] = 1;
                ans ++;
            }
            if (ans > 1) cnt ++;
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}
