//
//  main.cpp
//  A. The Text Splitting
//
//  Created by czf on 15/12/26.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
bool solve(int n, int p, int q, int &cnt_p, int &cnt_q){
    bool flag = 0;
    cnt_p = cnt_q = 0;
    int temp = n;
    for (int i = 1; i*p<=n; i++) {
        temp = n-i*p;
        if (temp%q == 0){
            cnt_p = i;
            cnt_q = temp/q;
            flag = 1;
            break;
        }
    }
    return flag;
}
int main(){
    int n, p ,q; scanf("%d%d%d",&n,&p,&q);
    string s; cin >> s;
    int cnt_p, cnt_q;
    if (p + q == n){
        printf("2\n");
        for(int i = 0; i < p; i ++) printf("%c",s[i]);
        printf("\n");
        for(int i = p; i < n; i ++) printf("%c",s[i]);
        printf("\n");
    }
    else if (n%p==0){
        printf("%d\n",n/p);
        for(int i = 0; i < n/p; i ++){
            for(int j = p*i; j < p*i+p; j ++)
                printf("%c",s[j]);
            printf("\n");
        }
    }
    else if (n%q==0 && q != p){
        printf("%d\n",n/q);
        for(int i = 0; i < n/q; i ++){
            for(int j = q*i; j < q*i+q; j ++)
                printf("%c",s[j]);
            printf("\n");
        }    }
    else if (solve(n, p, q, cnt_p, cnt_q)){
        printf("%d\n",cnt_p+cnt_q);
        for (int i = 0; i < cnt_p; i ++){
            for(int j = i*p; j < i*p+p; j ++) printf("%c",s[j]);
            printf("\n");
        }
        for (int i = 0; i < cnt_q; i ++){
            for(int j = i*q+cnt_p*p; j < i*q+q+cnt_p*p; j ++) printf("%c",s[j]);
            printf("\n");
        }
    }
    else printf("-1\n");
    return 0;
}