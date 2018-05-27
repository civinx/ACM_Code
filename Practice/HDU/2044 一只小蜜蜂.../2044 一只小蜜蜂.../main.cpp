//
//  main.cpp
//  2044 一只小蜜蜂...
//
//  Created by czf on 15/12/1.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    long long ans[60];
    while (t--){
        int a, b; scanf("%d%d",&a,&b);
        ans[a] = ans[a+1] = ans[b] = 1;
        for (int i = a+2; i <= b; i ++){
            ans[i] = ans[i-1] + ans[i-2];
        }
        printf("%lld\n",ans[b]);
    }
    return 0;
}
