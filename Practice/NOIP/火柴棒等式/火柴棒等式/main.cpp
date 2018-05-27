//
//  main.cpp
//  火柴棒等式
//
//  Created by czf on 2017/2/6.
//  Copyright © 2017年 czf. All rights reserved.
//

#include <iostream>
using namespace std;
const int num[10] = {6,2,5,5,4,5,6,3,7,6};
const int maxn = 1000;
int a[maxn];

void init() {
    for (int i = 0; i < maxn; i ++) {
        int temp = i, sum = 0;
        while (temp) {
            sum += num[temp%10];
            temp /= 10;
        }
        a[i] = sum;
    }
    a[0] = num[0];
}

int main() {
    init();
    int n, res = 0; cin >> n;
    for (int i = 0; i < maxn; i ++) {
        for (int j = 0; j < maxn; j ++) {
            if (a[i] + a[j] + a[i+j] == n - 4 && i + j < maxn) {
                res ++;
//                printf("%d + %d = %d\n",i,j,i+j);
            }
        }
    }
    cout << res << '\n';
}
