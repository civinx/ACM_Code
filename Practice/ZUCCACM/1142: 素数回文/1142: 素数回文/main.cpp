//
//  main.cpp
//  1142: 素数回文
//
//  Created by czf on 15/11/20.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <cstring>

const int maxn = 9989899 + 5;
bool isp[maxn];
int res[10000];
bool huiwen(int x){
    int temp = x;
    int b = 0;
    while(temp){
        b = b*10+temp%10;
        temp/=10;
    }
    return x == b;
}
int main(){
    int num = 0;
    int m = sqrt(maxn+0.5);
    memset(isp,0,sizeof(isp));
    for(int i = 2; i <= m; i ++) if(!isp[i])
        for(int j = i*i; j <= maxn; j += i) isp[j] = 1;
    for(int i = 5; i <= maxn; i += 2){
        if(!isp[i] && huiwen(i))
            res[num++] = i;
    }
    int a, b;
    while(scanf("%d%d",&a,&b) == 2){
        for(int i = 0; i < num; i ++){
            if(res[i] < a) continue;
            else if(res[i] <= b) printf("%d\n",res[i]);
            else break;
        }
        printf("\n");
    }
}