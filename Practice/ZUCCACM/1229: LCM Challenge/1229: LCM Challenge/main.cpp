//
//  main.cpp
//  1229: LCM Challenge
//
//  Created by czf on 15/11/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    long long n;
    while(scanf("%lld",&n) == 1){
        long long res;
        if (n < 3) {
            printf("%lld\n",n);
            continue;
        }
        else if(n%2) res = n*(n-1)*(n-2);
        else if (n%3) res = n*(n-1)*(n-3);
        else res = (n-1)*(n-2)*(n-3);
        printf("%lld\n",res);
    }
}