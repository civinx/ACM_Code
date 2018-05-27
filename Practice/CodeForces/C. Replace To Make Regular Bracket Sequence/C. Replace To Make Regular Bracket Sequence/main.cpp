#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 1000000 + 50;
char s[maxn], a[maxn];
bool left(char x){
    bool ret = 0;
    if (x == '(' || x == '[' || x == '{' || x == '<' ) ret = 1;
    return ret;
}
bool solve(char x, char y){
    bool ret = 0;
    if (x == '(' && y == ')') ret = 1;
    if (x == '[' && y == ']') ret = 1;
    if (x == '{' && y == '}') ret = 1;
    if (x == '<' && y == '>') ret = 1;
    return ret;
}
int main(){
    scanf("%s",s);
    int top = 0, cnt = 0, flag = 1;
    for(int i = 0; s[i] != '\0'; i++){
        if (left(s[i])){
            a[top++] = s[i];
        }
        else{
            if (top == 0){
                flag = 0;
                break;
            }
            if (!solve(a[top-1],s[i]))
                cnt ++;
            top--;
        }
    }
    if (flag && !top) printf("%d\n",cnt);
    else printf("Impossible\n");
    return 0;
}