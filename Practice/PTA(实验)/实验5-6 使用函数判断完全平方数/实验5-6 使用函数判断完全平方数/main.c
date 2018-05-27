#include <stdio.h>
#include <math.h>

int IsSquare( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    if ( IsSquare(n) ) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}

int IsSquare( int n ){
    int ret = 0;
    if ((int)sqrt(n)*(int)sqrt(n) == n) {
        ret = 1;
    }
    return ret;
}