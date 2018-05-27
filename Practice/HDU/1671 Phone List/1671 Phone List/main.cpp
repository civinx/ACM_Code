//
//  main.cpp
//  1671 Phone List
//
//  Created by czf on 16/1/31.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#define maxnode 40000
#define sigma_size 10
using namespace std;

struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int cnt[maxnode];
    int sz;
    bool flag;
    Trie () {
        sz = 1;
        flag = true;
        memset(ch[0], 0, sizeof(ch[0]));
        memset(val, 0, sizeof(val));
        memset(cnt, 0, sizeof(cnt));
    }
    int index(char c) { return c - '0'; }
    void insert(char *s){
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i ++){
            int c = index(s[i]);
            if (!ch[u][c]){
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];//当前个字母的位置
            cnt[u] ++;
            if (cnt[u] > 1 && (val[u] || i == n-1)) { flag = false; return; }
        }
        val[u] = 1;
    }
    bool solve() { return flag; }
};

int main(){
    int t; scanf("%d",&t);
    while(t--){
        char s[15];
        Trie trie;
        int n; scanf("%d",&n);
        while (n--) { scanf("%s",s); trie.insert(s); }
        trie.solve() ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}