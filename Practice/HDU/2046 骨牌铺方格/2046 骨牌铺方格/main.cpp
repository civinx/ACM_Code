//
//  main.cpp
//  2046 骨牌铺方格
//
//  Created by czf on 15/12/22.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int main(){
    long long a[55];
    a[1] = 1; a[2] = 2;
    for(int i = 3; i < 55; i ++){
        a[i] = a[i-1] + a[i-2];
    }
    int n;
    while(scanf("%d",&n) == 1){
        printf("%lld\n",a[n]);
    }
    return 0;
}