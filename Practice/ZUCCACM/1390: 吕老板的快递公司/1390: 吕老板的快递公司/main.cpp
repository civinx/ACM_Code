//
//  main.cpp
//  1390: 吕老板的快递公司
//
//  Created by czf on 15/11/10.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n, m;
    while (scanf("%d%d",&n,&m) == 2) {
        printf("%.f\n",pow(m, n)-1);
    }
    return 0;
}
