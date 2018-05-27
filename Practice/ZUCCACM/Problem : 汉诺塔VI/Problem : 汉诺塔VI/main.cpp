//
//  main.cpp
//  Problem : 汉诺塔VI
//
//  Created by czf on 15/11/9.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%.f\n",pow(3, n));
    }
    return 0;
}
