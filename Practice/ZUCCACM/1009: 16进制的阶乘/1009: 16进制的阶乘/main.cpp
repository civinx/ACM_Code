//
//  main.cpp
//  1009: 16进制的阶乘
//
//  Created by czf on 15/12/12.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cstring>
const int maxn = 500;
int num[maxn], res[maxn];

void solve(){
    memset(num,0,sizeof(num));
    memset(res,0,sizeof(res));
    num[0] = 1;
    for(int i = 2; i <= 205; i ++){
        int c = 0;
        for(int j = 0; j < maxn; j ++){
            int temp = num[j]*i + c;
            num[j] = temp % 16;
            c = temp / 16;
        }
        int index;
        for(index = maxn; index >= 0; index --) if (num[index]) break;
        for(int j = 0; j <= index; j ++) if (!num[j]) res[i] ++;
    }
}

int main(){
    int n;
    solve();
    while(scanf("%d",&n) && n != -1){
        printf("%d\n",res[n]);
    }
    return 0;
}