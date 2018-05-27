#include <stdio.h>
#define MAXN 20

void CountOff( int n, int m, int out[] );

int main()
{
    int out[MAXN], n, m;
    int i;
    
    scanf("%d %d", &n, &m);
    CountOff( n, m, out );
    for ( i = 0; i < n; i++ )
        printf("%d ", out[i]);
    printf("\n");
    
    return 0;
}
void CountOff( int n, int m, int out[] ){
    int cnt = 0;
    for (int i = 0; i < MAXN; i ++) out[i] = 0;
    int i = 0, ans = 0;
    for (;cnt<n;i++){
        if (i==n) i = 0;
        if (out[i] == 0){
            ans ++;
        }
        if (ans == m) {
            out[i] = ++cnt;
            ans = 0;
        }
    }
}