//
//  main.c
//  2最简分式（5分
//
//  Created by czf on 15/11/4.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <stdio.h>

int solve(int a, int b){
    int t;
    while (b) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    int fenzi, fenmu;
    scanf("%d/%d",&fenzi,&fenmu);
    int x = solve(fenzi,fenmu);
    fenzi /= x;
    fenmu /= x;
    printf("%d/%d",fenzi,fenmu);
    return 0;
}
