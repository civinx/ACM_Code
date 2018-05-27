//
//  main.cpp
//  1401: 序列变换
//
//  Created by czf on 15/12/6.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
const int maxn = 10000 + 5;
int s[maxn],temp[maxn];
int main(){
    int n, flag;
    while (scanf("%d",&n)==1) {
        s[0]= 0;
        for(int i = 1; i <= n; i ++){
            int a, b; scanf("%d%d",&a,&b);
            temp[i] = a-b;
        }
        std::sort(temp+1,temp+n+1);
        for (int i = 1; i <= n; i ++) {
            s[i] = s[i-1] + temp[i];
        }
        flag = 0;
        for(int i = 1; i < n; i ++){
            if(s[i] == s[n] - s[i]) {flag = 1; break;}
        }
        if (n == 1 && s[1] == 0) flag = 1;
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}