//
//  main.c
//  实验4-1-12 黑洞数
//
//  Created by czf on 15/11/12.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>
#define black 495

int max = 0, min = 0;

void solve(int n){
    int a, b, c, temp;
    a = n / 100;
    b = n / 10 % 10;
    c = n % 10;
    if (a > b) { temp = a; a = b; b = temp; }
    if (a > c) { temp = a; a = c; c = temp; }
    if (b > c) { temp = b; b = c; c = temp; }
    max = c*100 + b*10 + a;
    min = a*100 + b*10 + c;
}

int main() {
    int n, kase = 0;
    scanf("%d",&n);
    while (max - min != black && n != 0) {
        solve(n);
        n = max - min;
        printf("%d: %d - %d = %d\n",++kase,max,min,n);
    }
    return 0;
}
