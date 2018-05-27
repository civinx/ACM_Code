//
//  main.cpp
//  1143: 最大连续子序列
//
//  Created by czf on 15/12/10.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 10000 + 5;
int a[maxn];
int main(){
    int n;
    while (scanf("%d",&n) && n) {
        int sum = 0, maxnum = 0, max, min, index;
        for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
        min = a[0]; max = a[n-1];
        for(int i = 0; i < n; i ++){
            sum += a[i];
            if (sum > maxnum || (sum==0&&maxnum==0)){
                maxnum = sum;
                max = a[i];
                index = i;
            }
            if (sum < 0){
                sum = 0;
            }
        }
        if (maxnum >= 0){
            sum = 0;
            for (int i = index; i >= 0; i --) {
                sum += a[i];
                if (sum == maxnum){
                    min = a[i]; break;
                }
            }
        }
        printf("%d %d %d\n",maxnum,min,max);
    }
    return 0;
}