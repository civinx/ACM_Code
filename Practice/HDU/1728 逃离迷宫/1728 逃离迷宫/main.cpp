#include <cstdio>
const int inf = 0x4fffffff;
const int maxn = 100 + 5;
const int turn[4][2] = {0,1,0,-1,1,0,-1,0};
char pic[maxn][maxn];
int ans[maxn][maxn];
int m, n, k, x1, x2, y1, y2;
bool flag;
void dfs(int x, int y, int dir){
    if (flag){ //判断完成
        return;
    }
    if (x == x2 && y == y2){ 
        if (ans[x][y] <= k)
            flag = 1;
        return;
    }
    if (ans[x][y] > k){
        return;
    }
    if (ans[x][y] == k && x != x2 && y != y2){
        return;
    }
    for(int i = 0; i < 4; i ++){
        int next_x = x + turn[i][0];
        int next_y = y + turn[i][1];
        if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n){
            continue;
        }
        if (pic[next_x][next_y] == '*'){
            continue;
        }
        if (ans[next_x][next_y] < ans[x][y]){ //比老路还转的多肯定GG.
            continue;
        }
        if (dir != -1 && i != dir && ans[next_x][next_y] == ans[x][y]){//相等有点撞大运的希望，然而转向了那就比老路还不如.
            continue;
        }
        ans[next_x][next_y] = ans[x][y];
        if (dir != -1 && i != dir){
            ans[next_x][next_y] ++;
        }
        dfs(next_x, next_y, i);
    }
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        flag = 0;
        scanf("%d%d",&m,&n);
        for(int i = 0; i < m; i ++)
            scanf("%s",pic[i]);
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                ans[i][j] = inf;
        scanf("%d%d%d%d%d",&k,&y1,&x1,&y2,&x2);
        x1 --; x2 --; y1 --; y2 --;
        ans[x1][y1] = 0;
        dfs(x1, y1, -1);
        flag ? printf("yes\n") : printf("no\n");
    }
    return 0;
}