#include <stdio.h>

int reverse( int number );

int main()
{
    int n;
    
    scanf("%d", &n);
    printf("%d\n", reverse(n));
    
    return 0;
}
int reverse( int number ){
    int re;
    int tidai;
    int i;
    int mask = 1;
    if (number < 0) {
        tidai = number * -1;
    }
    else{
        tidai = number;
    }
    while (tidai / 10 != 0) {
        mask *= 10;
        tidai /= 10;
    }
    for (i = 1; i <= mask; i *= 10) {
        re += (number % 10) * (mask / i);
        number /= 10;
    }
    return re;
}