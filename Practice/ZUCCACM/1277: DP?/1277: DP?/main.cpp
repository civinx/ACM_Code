#include <cstdio>
const int maxn = 10 + 5;
int a[maxn], dp[maxn];
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        for (int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            dp[i] = 0;
        }
        int ans;
        dp[1] = 1;
        for(int i = 2; i <= n; i ++){
            ans = 0;
            for (int j = 1; j < i; j ++){
                if (a[i] > a[j] && dp[j] > ans)
                    ans = dp[j];
            }
            dp[i] = ans + 1;
        }
        ans = 0;
        for(int i = 1; i <= n; i ++)
            if(dp[i] > ans) ans = dp[i];
        printf("%d\n",ans);
    }
}