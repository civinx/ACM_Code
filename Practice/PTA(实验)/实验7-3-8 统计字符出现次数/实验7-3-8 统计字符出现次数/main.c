#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    gets(s);
    char x; scanf("%c",&x);
    int cnt = 0;
    for(int i = 0; i < strlen(s); i ++){
        if (x == s[i])
            cnt ++;
    }
    printf("%d",cnt);
    return 0;
}