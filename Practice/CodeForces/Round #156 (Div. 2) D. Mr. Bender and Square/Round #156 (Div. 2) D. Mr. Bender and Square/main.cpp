//
//  main.cpp
//  Round #156 (Div. 2) D. Mr. Bender and Square
//
//  Created by czf on 15/12/9.
//  Copyright © 2015年 czf. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int main(){
    LL n, x, y, c, sum = 0;
    LL d, xu, xd, yl, yr, i;
    cin >> n >> x >> y >> c;
    x --; y --;
    for(i = 0; sum < c; i ++){
        sum = i*i + (i+1)*(i+1);
        if (sum < c) continue;
        xu = x-i; xd = x+i; yl = y-i; yr = y+i;
        if (xu < 0) sum -= xu*xu;
        if (xd > n-1) sum -= (xd-n+1)*(xd-n+1);
        if (yl < 0){
            sum -= yl * yl;
            d = -yl; d--;
            if (x-d < 0) sum += (x-d)*(x-d-1)/2;
            if (x+d > n-1) sum += (x+d-n+1)*(x+d-n+2)/2;
        }
        if(yr > n-1){
            sum -= (yr-n+1)*(yr-n+1);
            d = yr-n;
            if (x-d < 0) sum += (x-d)*(x-d-1)/2;
            if (x+d > n-1) sum += (x+d-n+1)*(x+d-n+2)/2;
        }
    }
    cout << i-1 << endl;
}