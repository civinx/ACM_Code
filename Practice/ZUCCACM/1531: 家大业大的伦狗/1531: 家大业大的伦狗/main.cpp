//
//  main.cpp
//  1531: 家大业大的伦狗
//
//  Created by czf on 16/3/12.
//  Copyright © 2016年 czf. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
int a[maxn];
int main(){
    int n, k;
    while(scanf("%d%d",&n,&k) == 2){
        if (n >= k){
            for(int i = 0; i < n; ++ i)
                scanf("%d",&a[i]);
            sort(a,a+n);
            printf("%d\n",a[n-k]);
            continue;
        }
        long long sum = 0, ans;
        for(int i = 0; i < n; ++ i){
            scanf("%d",&a[i]);
            sum += a[i];
        }
        ans = sum / n;
        long long cnt = 0;
        bool flag = 0;
        while(ans){
            cnt = 0;
            for(int i = 0; i < n; i ++){
                cnt += a[i]/ans;
                if (cnt >= k){
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
            ans --;
        }
        if (flag) printf("%lld\n",ans);
        else printf("0\n");
    }
    return 0;
}