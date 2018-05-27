//
//  main.cpp
//  1106: 最后留下的是几号?
//
//  Created by czf on 15/11/18.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        long long sum = 1;
        int i;
        for(i = 0;;i++){
            sum += (long long)pow(2,i);
            if (sum >= n)
                break;
        }
        int index = n-(sum-pow(2,i));
//        printf("index = %d ",index);
        if (n == 1)
            printf("1\n");
        else
            printf("%d\n",index*2);
    }
}