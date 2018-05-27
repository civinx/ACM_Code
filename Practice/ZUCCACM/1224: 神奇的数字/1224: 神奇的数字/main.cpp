//
//  main.cpp
//  1224: 神奇的数字
//
//  Created by czf on 15/11/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <cmath>
const int maxn = 2147483647;

int main(){
    int m ,n;
    while(scanf("%d%d",&m,&n) == 2){
        int l = (int)log10(n) + 1;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= l; i ++){
            for(int j = 10; j >= 2; j --){
                if (pow(10,i)/j > maxn) continue;
                if((long long)pow(10,i)%j==0 && pow(10,i)/j <= n)
                    cnt1 ++;
                }
        }
        l = (int)log10(m) + 1;
        for(int i = 1; i <= l; i ++){
            for(int j = 10; j >= 2; j --){
                if (pow(10,i)/j > maxn) continue;
                if((long long)pow(10,i)%j==0 && pow(10,i)/j < m)
                    cnt2 ++;
                }
        }
        printf("%d\n",cnt1-cnt2);
    }
}
