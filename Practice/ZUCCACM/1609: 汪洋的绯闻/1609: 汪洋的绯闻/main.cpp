//
//  main.cpp
//  1609: 汪洋的绯闻
//
//  Created by czf on 15/12/21.
//  Copyright © 2015年 czf. All rights reserved.
//


#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main(){
    int res[15];
    res[1] = 1; res[2] = 2;
    for(int i = 3; i <= 13; i ++){
        res[i] = res[i-1] + (i-1)*res[i-2];
    }
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        printf("%d\n",res[n]);
    }
    return 0;
}