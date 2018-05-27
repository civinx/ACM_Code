//
//  main.cpp
//  1200: 不重复数字
//
//  Created by czf on 15/11/15.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

const int maxn = 100000 + 5;
int a[maxn];
set<int> num;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n, x;
        num.clear();
        scanf("%d",&n);
        scanf("%d",&x);
        printf("%d",x);
        num.insert(x);
        for(int i = 1; i < n; i ++){
            scanf("%d",&x);
            if(!num.count(x)){
                printf(" %d",x);
                num.insert(x);
            }
        }
        printf("\n");
    }
}