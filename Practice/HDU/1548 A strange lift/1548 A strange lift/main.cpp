//
//  main.cpp
//  1548 A strange lift
//
//  Created by czf on 16/2/5.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 200 + 10;
int k[maxn], vis[maxn], cnt[maxn];
int n, a, b;
void bfs(int fir){
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    queue<int> q;
    q.push(fir);
    vis[fir] = 1;
    while(!q.empty()){
        fir = q.front(); q.pop();
        if (fir == b){
            printf("%d\n",cnt[fir]);
            return;
        }
        for(int i = -1; i <= 1; i += 2){
            int next = fir + k[fir]*i;
            if (next > 0 && next <= n && !vis[next]){
                q.push(next); vis[next] = 1;
                cnt[next] = cnt[fir]+1;
            }
        }
    }
    printf("-1\n");
}
int main(){
    while(scanf("%d",&n) && n){
        scanf("%d%d",&a,&b);
        for(int i = 1; i <= n; i ++){
            scanf("%d",&k[i]);
        }
        bfs(a);
    }
    return 0;
}