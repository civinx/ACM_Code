//
//  main.cpp
//  1117: SRETAN
//
//  Created by czf on 15/11/5.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 32;
int a[maxn];
int main() {
    int k;
    while (scanf("%d",&k) == 1) {
        int i = 0;
        k++;
        while (k) {
            a[i] = k % 2;
            k /= 2;
            i ++;
        }
        for (i = i-2; i >= 0; i --) {
            printf("%d",a[i]==0 ? 4:7);
        }
        printf("\n");
    }
    return 0;
}
