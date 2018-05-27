//
//  main.cpp
//  1288: 节目安排
//
//  Created by czf on 15/12/14.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 50 + 5;
int main(){
    int t, a[maxn]; scanf("%d",&t);
    while(t--){
        int n, k, cnt = 0, flag = 0;
        scanf("%d%d",&n,&k);
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        for(int i = 0; i < n; i ++){
            int ans = 0;
            for(int m = 0; m < i; m ++) ans += a[n-m-1];
            for(int j = 0; j < n-i; j ++){
                if (flag) printf(" "); flag = 1;
                printf("%d",a[j]+ans);
                cnt ++;
                if (cnt == k) break;
            }
            if (cnt == k) break;
        }
        printf("\n");
    }
    return 0;
}
