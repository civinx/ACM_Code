//
//  main.cpp
//  1603: Another simple question
//
//  Created by czf on 15/12/3.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
typedef unsigned long long LL;
int solve(LL a, LL b, LL c, LL d){
    if (a/b > c/d) return 1;
    else if (a/b < c/d) return -1;
    else{ //全是0 倍数一样
        if (a==b){
            if (c > d) return -1;
            else return 1;
        }
        if (c==d){
            if (a > b) return 1;
            else return -1;
        }
        LL x = a/b;
        LL r1,r2,r3,r4;
        r1 = b; r2 = a-x*b; r3 = d; r4 = c-x*d;
        if (a%b == 0){
            if (c%d!=0) return -1;
        }
        if (c%d == 0){
            if (a%b!=0) return 1;
        }
        return -solve(r1, r2, r3, r4);
    }
}
int main(){
    LL a, b, c ,d;
    while(scanf("%llu%llu%llu%llu",&a,&b,&c,&d) == 4){
        int res = 0; //左大res == 1  右大res == -1
        res = solve(a, b, c, d);
        if (res == 1) printf("tza\n");
        else printf("riu\n");
    }
    return 0;
}