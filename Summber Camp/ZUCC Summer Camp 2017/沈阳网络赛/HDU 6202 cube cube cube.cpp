#include <cstdio>
const int maxn = 73;
int a[maxn];
const int b[8][18] = {
    {19,10,12,11,15,14,54,41,42,43,44,45,68,36,35,31,30,28},
    {28,19,21,20,24,23,63,50,51,52,53,54,41,9, 8, 4, 3, 1},
    {1 ,28,30,29,33,32,72,59,60,61,62,63,50,18,17,13,12,10},
    {10,1, 3, 2, 6, 5, 45,68,69,70,71,72,59,27,26,22,21,19},
    {55,64,66,65,69,68,36,5, 6, 7, 8, 9, 14,54,53,49,48,46},
    {64,37,39,38,42,41,9, 14,15,16,17,18,23,63,62,58,57,55},
    {37,46,48,47,51,50,18,23,24,25,26,27,32,72,71,67,66,64},
    {46,55,57,56,60,59,27,32,33,34,35,36,5, 45,44,40,39,37}
};

const int MI[8] = {1,10,19,28,37,46,55,64};

const int c[4][18] {
    {2, 3, 4, 11,15,16,52,51,47,58,57,56,67,71,70,34,35,31},
    {11,12,13,20,24,25,61,60,56,67,66,65,40,44,43,7, 8, 4},
    {20,21,22,29,33,34,70,69,65,40,39,38,49,53,52,16,17,13},
    {29,30,31,2, 6, 7, 43,42,38,49,48,47,58,62,61,25,26,22}
};



void nsz(const int * b, int s) {
    int temp[maxn];
    for (int i = 0; i < 18; i ++) {
        int pos = (i+s)%18;
        temp[b[i]] = a[b[pos]];
    }
    for (int i = 0; i < 18; i ++) {
        a[b[i]] = temp[b[i]];
    }
}

void ssz(const int * b, int s) {
    int temp[maxn];
    for (int i = 0; i < 18; i ++) {
        int pos = ((i-s) % 18 + 18) % 18;
        temp[b[i]] = a[b[pos]];
    }
    for (int i = 0; i < 18; i ++) {
        a[b[i]] = temp[b[i]];
    }
}

void ssz(int mi) {
    int t[maxn];
    int p[10];
    for (int i = 1; i <= 9; i ++) p[i] = mi + i - 1;
    
    t[p[9]] = a[p[1]];
    t[p[5]] = a[p[9]];
    t[p[1]] = a[p[5]];
    
    t[p[3]] = a[p[6]];
    t[p[8]] = a[p[3]];
    t[p[6]] = a[p[8]];
    
    t[p[4]] = a[p[2]];
    t[p[7]] = a[p[4]];
    t[p[2]] = a[p[7]];
    for (int i = 1; i <= 9; i ++) a[p[i]] = t[p[i]];
}

void nsz(int mi) {
    int t[maxn];
    int p[10];
    for (int i = 1; i <= 9; i ++) p[i] = mi + i - 1;
    t[p[5]] = a[p[1]];
    t[p[9]] = a[p[5]];
    t[p[1]] = a[p[9]];
    
    t[p[6]] = a[p[3]];
    t[p[8]] = a[p[6]];
    t[p[3]] = a[p[8]];
    
    t[p[7]] = a[p[2]];
    t[p[4]] = a[p[7]];
    t[p[2]] = a[p[4]];
    for (int i = 1; i <= 9; i ++) a[p[i]] = t[p[i]];
}


bool check() {
//    for (int i = 1; i <= 72; i ++) printf("%d%c",a[i],i%9==0?'\n':' ');
//    printf("\n");
    for (int i = 0; i < 8; i ++) {
        for (int j = MI[i]; j <= MI[i] + 8; j ++) {
            if (a[j] != a[MI[i]]) return false;
        }
    }
    return true;
}

bool flag;

void dfs(int step) {
    if (check() || flag) {
        flag = 1;
        return;
    }
    if (step >= 3) return;
    
    int t[maxn];
    for (int i = 1; i <= 72; i ++) t[i] = a[i];
    
    for (int i = 0; i < 8; i ++) {
        ssz(b[i], 6);
        ssz(MI[i]);
        dfs(step + 1);
        for (int j = 1; j <= 72; j ++) a[j] = t[j];
        
        nsz(b[i], 6);
        nsz(MI[i]);
        dfs(step + 1);
        for (int j = 1; j <= 72; j ++) a[j] = t[j];
    }
    
    for (int i = 0; i < 4; i ++) {
        ssz(c[i], 6);
        dfs(step + 1);
        for (int j = 1; j <= 72; j ++) a[j] = t[j];
        
        nsz(c[i], 6);
        dfs(step + 1);
        for (int j = 1; j <= 72; j ++) a[j] = t[j];
    }
}

void test() {
    int t[maxn];
    for (int i = 1; i <= 72; i ++) t[i] = a[i];
    
    for (int i = 0; i < 8; i ++) {
        ssz(b[i], 6);
        ssz(MI[i]);
        ssz(b[i], 6);
        ssz(MI[i]);
        for (int j = 1; j <= 72; j ++) printf("%d%c",a[j],j%9==0?'\n':' ');
        for (int j = 1; j <= 72; j ++) a[j] = t[j];
        printf("\n");
        for (int j = 1; j <= 72; j ++) printf("%d%c",a[j],j%9==0?'\n':' ');
        printf("\n");
        nsz(b[i], 6);
        nsz(MI[i]);
        for (int j = 1; j <= 72; j ++) printf("%d%c",a[j],j%9==0?'\n':' ');
        for (int j = 1; j <= 72; j ++) a[j] = t[j];
        printf("\n\n");
    }
}
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        for (int i = 1; i <= 72; i ++) scanf("%d",&a[i]);
        printf("\n");
//        test();
//        for (int i = 1; i <= 72; i ++) printf("%d%c",a[i],i%9==0?'\n':' ');
        flag = 0;
        dfs(0);
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
