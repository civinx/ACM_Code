//
//  main.cpp
//  1161: 集气袋
//
//  Created by czf on 15/12/5.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
const int maxn = 10000 + 5;
int a[maxn];
int main(){
    int n, m;
    while(scanf("%d%d",&n,&m) == 2){
        for(int i = 1; i <= n; i ++)
            scanf("%d",&a[i]);
        int flag = 1, sum = 0, res = 1;;
        for(int i = 1; i < n; i ++){
            if (sum + a[i] < m)
                sum += a[i];
            else if (flag){
                flag = 0;
                if (a[i] < m)
                    sum = a[i];
                else{
                    res = 0;
                    break;
                }
            }
            else{
                res = 0;
                break;
            }
        }
        if (res) printf("%d\n",sum+a[n]);
        else printf("It's Imposible!\n");
    }
    return 0;
}