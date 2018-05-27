//
//  main.cpp
//  HDU ACM组队安排
//
//  Created by czf on 15/12/2.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 20 + 5;
long long a[maxn] = {0,1,2,5};
int main(){
    for(int i = 4; i <= 20; i ++){
        a[i] = a[i-1] + a[i-2] * (i-1) + a[i-3] * ((i-1)*(i-2)/2);
    }
    int n;
    while (scanf("%d",&n) && n){
        printf("%lld\n",a[n]);
    }
}