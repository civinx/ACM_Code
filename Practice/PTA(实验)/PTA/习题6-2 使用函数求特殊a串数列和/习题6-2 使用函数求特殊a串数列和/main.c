#include <stdio.h>

int fn( int a, int n );
int SumA( int a, int n );

int main()
{
    int a, n;
    
    scanf("%d %d", &a, &n);
    printf("fn(%d, %d) = %d\n", a, n, fn(a,n));
    printf("s = %d\n",SumA(a,n));
				
    return 0;
}

int fn( int a, int n ){
    int ret = 0;
    int i;
    int j = 1;
    for (i = 1; i <= n; i ++) {
        ret += a * j;
        j *= 10;
    }
    return ret;
}
int SumA( int a, int n ){
    int ret = 0;
    int sum = 0;
    int i;
    int j = 1;
    for (i = 1; i <= n; i ++) {
        ret += a * j;
        sum += ret;
        j *= 10;
    }

    return sum;
}
