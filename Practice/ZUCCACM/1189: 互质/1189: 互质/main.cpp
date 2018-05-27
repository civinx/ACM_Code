//
//  main.cpp
//  1189: 互质
//
//  Created by czf on 15/11/19.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int enler(int n){
    int ret = n, a = n;
    for(int i = 2; i*i <= a; i ++){
        if(a%i == 0){
            ret = ret/i*(i-1);
            while(a%i == 0) a /= i;
        }
    }
    if(a>1) ret = ret/a*(a-1); //最后剩下的素数 如 39/3 -> 13 或 7 -> 7
    return ret;
}

int main(){
    int n;
    while(scanf("%d",&n) == 1){
        printf("%d\n",enler(n));
    }
}