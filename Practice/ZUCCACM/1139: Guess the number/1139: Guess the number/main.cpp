//
//  main.cpp
//  1139: Guess the number
//
//  Created by czf on 15/11/10.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int i, a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        for (i = 1000; i <= 9999; i ++) {
            if (i%a == 0 && (i+1)%b == 0 && (i+2)%c == 0)
                break;
        }
        if (i >= 1000 && i <= 9999)
            printf("%d\n",i);
        else
            printf("Impossible\n");
    }
    return 0;
}
