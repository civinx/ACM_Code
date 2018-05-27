//
//  main.c
//  1014: 求和
//
//  Created by czf on 15/10/9.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define MAXN 10000

int main() {
    int n;
    long long sum;
    int i;
    int x;
    
    while  (scanf("%d",&n) != EOF) {
        
        sum = 0;
        
        for (i = 1; i <= n; i ++) {
            if (i == MAXN) {
                break;
            }
            sum += n / i;
        }
        
        if(n >= MAXN){                        //n除以i=最后一项等于值等于i的序号
            x = n / MAXN;                     //算出x(第MAXN项的值),i从x开始。
            for (i = x; i > 0; i --) {        //i是项的值
                if (i == x) {
                    sum += x * (n / i - MAXN + 1); /* n/i是值等于x的最后一项的项序号 ，-MAXN+1是值等于x的项序号。*/
                }
                else{
                    sum += i * ((n / i) - n / (i + 1)); /* n/i值等于i的最后一项的序号，n/(i+1)是值等于i+1的最后一项的序号相减为值为i的项个数*/
                }
            }
        }
        
        printf("%lld\n",sum);
    }
    return 0;
}
