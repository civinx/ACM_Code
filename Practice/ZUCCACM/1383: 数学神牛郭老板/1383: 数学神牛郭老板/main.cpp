//
//  main.cpp
//  1383: 数学神牛郭老板
//
//  Created by czf on 15/11/21.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int gcd(int a, int b){
    return b==0 ? a : gcd(b,a%b);
}
int main(){
    int t, a[25], b[25];
    scanf("%d",&t);
    while(t--){
        int n, m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i <= n; i ++) scanf("%d",&a[i]);
        for (int i = 0; i <= m; i ++) scanf("%d",&b[i]);
        if (n > m){
            int flag = 1;
            if (a[0] < 0) flag *= -1;
            if (b[0] < 0) flag *= -1;
            if (flag == 1) printf("Infinity\n");
            else printf("-Infinity\n");
        }
        else if (n < m){
            printf("0/1\n");
        }
        else{
            int sign = 1;
            if (a[0] < 0) {sign *= -1; a[0] *= -1;}
            if (b[0] < 0) {sign *= -1; b[0] *= -1;}
            int g = gcd(a[0],b[0]);
            printf("%d/%d\n",a[0]/g*sign,b[0]/g);
        }
    }
    return 0;
}

