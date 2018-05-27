//
//  main.cpp
//  1485: Problem B
//
//  Created by czf on 15/11/12.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
int a[10];

int length(int n, int k){
    int res = 0;
    while (n) {
        n /= k;
        res++;
    }
    return res;
}

int isnum(int n, int l, int k){
    int ret = 1;
    for (int i = 0; i < l; i++) {
        a[i] = n%k;
        n /= k;
    }
    for (int i = 0; i < l; i ++) {
        if (a[i] != a[l-i-1]){
            ret = 0;
            break;
        }
    }
    return ret;
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n, k;
        scanf("%d%d",&n,&k);
        if (isnum(n, length(n, k), k))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
