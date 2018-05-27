//
//  main.cpp
//  1630: 有趣的博弈
//
//  Created by czf on 16/3/28.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
typedef long long ll;
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        double n; scanf("%lf",&n);
        while(n > 1) n /= 18;
        if (n <= 0.5) printf("1\n");
        else printf("2\n");
    }
    return 0;
}