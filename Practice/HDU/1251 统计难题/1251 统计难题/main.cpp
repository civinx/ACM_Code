//
//  main.cpp
//  1251 统计难题
//
//  Created by czf on 16/1/31.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
#define maxnode 400000
#define sigma_size 26
struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int cnt[maxnode];
    int sz;
    Trie () { sz = 1; memset(ch[0],0,sizeof(ch[0])); memset(cnt, 0, sizeof(cnt)); }
    int index(char c) { return c - 'a'; }
    void insert(char *s, int v){
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i ++){
            int c = index(s[i]);
            if (!ch[u][c]){
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
            cnt[u] ++;
        }
        val[u] = v;
    }
    int find_qz(char *s){
        int u = 0, n = strlen(s), i;
        for(i = 0; i < n; i ++){
            int c = index(s[i]);
            if (ch[u][c]) u = ch[u][c];
            else break;
        }
        if (i == n) return cnt[u];
        return 0;
    }
};

int main(){
    char s[15];
    Trie trie;
    while (gets(s) && s[0] != '\0') trie.insert(s, 1);
    while (scanf("%s",s) != EOF) printf("%d\n",trie.find_qz(s));
    return 0;
}
