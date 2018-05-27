#include <cstdio>
#include <cstring>
const int maxn = 100 + 5;
char a[maxn*maxn], b[maxn];
int next[maxn];

void GetNext(){
    next[0] = next[1] = 0;
    auto m = strlen(b);
    for(int i = 1; i < m; i ++){
        int j = next[i];
        while(j && b[i] != b[j]) j = next[j];
        next[i+1] = b[i] == b[j] ? j+1 : 0;
//        if (b[i+1] == b[j+1]) next[i+1] = next[j+1];
    }
}

int kmp(){
    GetNext();
    int cnt = 0, j = 0;
    auto m = strlen(a);
    for(int i = 0; i < m; i ++){
        while (j && a[i] != b[j]) j = next[j];
        if (a[i] == b[j]) j ++;
        if (j == strlen(b)){
            cnt ++;
            j = next[j];
        }
    }
    return cnt;
}

int main(){
    while (scanf("%s%s",a,b) != EOF)
        printf("%d\n",kmp());
    return 0;
}