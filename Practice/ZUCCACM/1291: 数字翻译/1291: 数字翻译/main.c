//
//  main.c
//  1291: 数字翻译
//
//  Created by czf on 15/10/17.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int main() {
    int n;
    char a[11][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
    int t;
    scanf("%d",&t);
    while (t --) {
        scanf("%d",&n);
        if (n <= 10) printf("%s\n",a[n]);
        else if (n % 10 == 0) printf("%s %s\n",a[n/10],a[10]);
        else if (n > 10 && n < 20) printf("%s %s\n",a[10],a[n%10]);
        else printf("%s %s %s\n",a[n/10],a[10],a[n%10]);
    }
}