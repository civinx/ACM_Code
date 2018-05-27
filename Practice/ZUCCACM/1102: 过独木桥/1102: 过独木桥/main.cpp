//
//  main.cpp
//  1102: 过独木桥
//
//  Created by czf on 15/11/18.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
int main(){
    int n, a[maxn];
    while(scanf("%d",&n) == 1){
        int res = 0;
        for(int i = 1; i <= n; i ++)
            scanf("%d",&a[i]);
        sort(a,a+n+1);
        if (n == 3)
            res = a[1] + a[2] + a[3];
        else{
            if (n%2 == 0){
                for(int i = 4; i <= n; i += 2){
                    res += a[1] + a[2]*2 + a[i];
                }
                res += a[2];
            }
            else{
                for (int i = 5; i <= n; i += 2) {
                    res += a[1] + a[2]*2 + a[i];
                }
                res += a[1]+2*a[2]+a[3];
                res -= a[2];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

